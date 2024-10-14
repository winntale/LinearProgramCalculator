#include "lpwidget.h"
#include "ui_lpwidget.h"
#include <QMessageBox>
#include <QPainter>
#include <QPen>
#include <algorithm>

LpWidget::LpWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::LpWidget) {
    ui->setupUi(this);

    // Подключение слота к кнопке
    connect(ui->solveButton, &QPushButton::clicked, this, &LpWidget::solveAndDraw);
}

LpWidget::~LpWidget() {
    delete ui;
}

void LpWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED( event )

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QStyleOption opt;
    opt.initFrom(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);

    this->setStyleSheet("background-color:#323232;");
    ui->solveButton->setStyleSheet("background-color:#525252;");

    // Нарисуем оси координат
    painter.drawLine(50, 550, 550, 550); // Ось x
    painter.drawLine(50, 550, 50, 50);   // Ось y

    // Подписи для осей
    painter.drawText(560, 560, "x1");
    painter.drawText(10, 60, "x2");

    // Добавим значения вдоль оси x1
    for (int i = 0; i <= static_cast<int>(10 / scaleFactor); ++i) {
        int x = 50 + i * (500 * scaleFactor) / 10;  // Расчет позиции на оси x
        painter.drawLine(x, 545, x, 555);  // Маленькие засечки на оси x
        painter.drawText(x - 10, 570, QString::number(i));  // Подписи
    }

    // Добавим значения вдоль оси x2
    for (int i = 0; i <= static_cast<int>(10 / scaleFactor); ++i) {
        int y = 550 - i * (500 * scaleFactor) / 10;  // Расчет позиции на оси y
        painter.drawLine(45, y, 55, y);  // Маленькие засечки на оси y
        painter.drawText(30, y + 10, QString::number(i));  // Подписи
    }


    // Отрисуем ограничения
    QPen pen(Qt::blue, 2);
    painter.setPen(pen);

    // Сначала нарисуем все линии ограничений
    for (const auto& constraint : constraints) {
        double a1, b1, c1;
        QString sign;
        std::tie(a1, b1, c1, sign) = constraint;

        if (b1 != 0) {
            int x1 = 50;
            int y1 = static_cast<int>(550 - (c1 / b1) * (500 * scaleFactor) / 10); // Прямая на оси y
            int y2 = 550;

            int x2;
            if (a1 != 0) {
                x2 = static_cast<int>(50 + (c1 / a1) * (500 * scaleFactor) / 10);  // Прямая на оси x
                if (x2 > 550) {
                    x2 = 550;
                    double x = (x2 - 50) * 10 / (500 * scaleFactor);
                    y2 = static_cast<int>(550 - ((c1 - a1*x) / b1) * (500 * scaleFactor) / 10);
                }
                if (y1 < 50) {
                    y1 = 50;
                    double y = (550 - y1) * 10 / (500 * scaleFactor);
                    x1 = static_cast<int>(50 + ((c1 - b1*y) / a1) * (500 * scaleFactor) / 10);
                }
            } else {
                x2 = 50;  // Если a1 == 0, линия параллельна оси x
            }

            painter.drawLine(x1, y1, x2, y2);

        }
    }

    // Рисуем целевую функцию (линия)
    QPen objectivePen(Qt::green, 1, Qt::DashLine);  // Линия целевой функции (зеленая пунктирная)
    painter.setPen(objectivePen);

    double targetValue = ui->targetSlider->value();
    if (b != 0) {
        int x1 = 50;
        int y1 = static_cast<int>(550 - (targetValue / b) * (500 * scaleFactor) / 10);
        int y2 = 550;

        int x2;
        if (a != 0) {
            x2 = static_cast<int>(50 + (targetValue / a) * (500 * scaleFactor) / 10);  // Прямая на оси x
            if (x2 > 550) {
                x2 = 550;
                double x = (x2 - 50) * 10 / (500 * scaleFactor);
                y2 = static_cast<int>(550 - ((targetValue - a*x) / b) * (500 * scaleFactor) / 10);
            }
            if (y1 < 50) {
                y1 = 50;
                double y = (550 - y1) * 10 / (500 * scaleFactor);
                x1 = static_cast<int>(50 + ((targetValue - b*y) / a) * (500 * scaleFactor) / 10);
            }
        } else {
            x2 = 50;  // Если a1 == 0, линия параллельна оси x
        }

        painter.drawLine(x1, y1, x2, y2);
    }

    // Найдем все пересечения
    QVector<QPointF> intersectionPoints;
    for (size_t i = 0; i < constraints.size(); ++i) {
        for (size_t j = 0; j < constraints.size(); ++j) {
            if (i != j) {
                QPointF intersection;
                if (findIntersection(constraints[i], constraints[j], intersection)) {
                    intersectionPoints.push_back(intersection);
                }
            }
        }
    }
    // Оставляем только пересечения, которые находятся внутри всех ограничений
    QVector<QPointF> feasiblePoints;
    for (const QPointF& point : intersectionPoints) {
        if (isFeasiblePoint(point)) {
            feasiblePoints.push_back(point);
        }
    }


    // Сортируем точки для построения выпуклого четырехугольника или многоугольника
    if (!feasiblePoints.isEmpty()) {
        sortPointsClockwise(feasiblePoints);
        painter.setPen(Qt::NoPen);
        painter.setBrush(QBrush(QColor(0, 0, 255, 50))); // Полупрозрачный синий цвет

        if (!hasSolution) {
            QPolygonF infeasibleArea;
            // Рисуем заливку для области, где нет решения (можно использовать прямоугольник или многоугольник)
            infeasibleArea << feasiblePoints << QPointF(550, 550) << QPointF(550, 50) << QPointF(50, 50);
            painter.drawPolygon(infeasibleArea);
        }
        else painter.drawPolygon(feasiblePoints.constData(), feasiblePoints.size());

        QPolygonF xAxisRectangle;
        QPolygonF yAxisRectangle;

        painter.setBrush(QColor(50, 50, 50));
        xAxisRectangle << QPointF(550, 550) << QPointF(this->width(), 550) << QPointF(this->width(), 0) << QPointF(550, 0);
        yAxisRectangle << QPointF(0, 0) << QPointF(550, 0) << QPointF(550, 50) << QPointF(0, 50);
        painter.drawPolygon(xAxisRectangle);
        painter.drawPolygon(yAxisRectangle);

        // Подписи для осей
        painter.drawText(560, 560, "x1");
        painter.drawText(30, 30, "x2");

        // Отметим точки пересечения красным цветом
        QPen pointPen(Qt::red, 5); // Жирный красный цвет для точек
        painter.setPen(pointPen);
        for (const QPointF& point : feasiblePoints) {
            if (point.x() < 550) painter.drawPoint(point); // Рисуем каждую точку пересечения

            // Преобразуем координаты для правильного отображения
            double x = (point.x() - 50) * 10 / (500 * scaleFactor);
            double y = (550 - point.y()) * 10 / (500 * scaleFactor);

            // Форматируем координаты с одним знаком после запятой
            QString pointText = "(" + QString::number(x, 'f', 1) + ", " + QString::number(y, 'f', 1) + ")";

            // Отрисовка текста рядом с точкой
            if (point.x() < 550) painter.drawText(point.x() + 5, point.y() - 5, pointText);  // Смещаем подпись на пару пикселей от самой точки
        }
    }
}

bool LpWidget::findIntersection(const std::tuple<double, double, double, QString>& line1,
                                const std::tuple<double, double, double, QString>& line2, QPointF& intersection) {
    double a1, b1, c1, a2, b2, c2;
    QString sign1, sign2;
    std::tie(a1, b1, c1, sign1) = line1;
    std::tie(a2, b2, c2, sign2) = line2;

    double det = a1 * b2 - a2 * b1;
    if (det == 0) {
        return false; // Прямые параллельны, нет пересечения
    }

    // Пересчет точек пересечения
    double x = (b2 * c1 - b1 * c2) / det;
    double y = (a1 * c2 - a2 * c1) / det;

    // Проверка, что пересекаемая точка лежит в первой четверти
    if (x >= 0 && y >= 0) {
        // Преобразуем координаты для отрисовки
        intersection = QPointF(50 + x * 500 * scaleFactor / 10, 550 - y * 500 * scaleFactor / 10);
        return true;
    }
    return false;
}

bool LpWidget::isFeasiblePoint(const QPointF& point) {
    // Проверка, лежит ли точка внутри всех ограничений
    for (const auto& constraint : constraints) {
        double a1, b1, c1;
        QString sign;
        std::tie(a1, b1, c1, sign) = constraint;

        double x = (point.x() - 50) * 10 / (500 * scaleFactor);
        double y = (550 - point.y()) * 10 / (500 * scaleFactor);

        double value = a1 * x + b1 * y;

        // Учитываем разные типы ограничений
        const double epsilon = 1e-6;  // Допуск для проверки
        if (sign == "<=" && value > c1 + epsilon) {
            return false;
        }
        if (sign == ">=" && value < c1 - epsilon) {
            return false;
        }
    }
    return true;
}

void LpWidget::sortPointsClockwise(QVector<QPointF>& points) {
    // Найдем центр точек
    QPointF center(0, 0);
    for (const QPointF& point : points) {
        center += point;
    }
    center /= points.size();

    // Сортировка по углу относительно центра (в порядке обхода по часовой стрелке)
    std::sort(points.begin(), points.end(), [center](const QPointF& p1, const QPointF& p2) {
        double angle1 = std::atan2(p1.y() - center.y(), p1.x() - center.x());
        double angle2 = std::atan2(p2.y() - center.y(), p2.x() - center.x());
        return angle1 < angle2;
    });
}

void LpWidget::parseConstraint(QLineEdit *editX1, QLineEdit *editX2, QComboBox *signBox, QLineEdit *editValue) {
    // Чтение коэффициентов ограничения
    double a1 = editX1->text().toDouble();
    double b1 = editX2->text().toDouble();
    double c1 = editValue->text().toDouble();
    QString signValue = signBox->currentText();
    constraints.push_back(std::make_tuple(a1, b1, c1, signValue));
}

void LpWidget::solveAndDraw() {
    // Очищаем список ограничений перед расчетом
    constraints.clear();
    hasSolution = true;  // Сначала предполагаем, что решение есть

    // Чтение коэффициентов целевой функции
    a = ui->funcEditX1->text().toDouble();
    b = ui->funcEditX2->text().toDouble();
    QString purpose = ui->funcPurposeBox->currentText();

    // Чтение ограничений
    parseConstraint(ui->constraint1EditX1, ui->constraint1EditX2, ui->constraint1SignBox, ui->constraint1EditValue);
    parseConstraint(ui->constraint2EditX1, ui->constraint2EditX2, ui->constraint2SignBox, ui->constraint2EditValue);
    parseConstraint(ui->constraint3EditX1, ui->constraint3EditX2, ui->constraint3SignBox, ui->constraint3EditValue);

    // Добавляем стандартные ограничения
    constraints.push_back(std::make_tuple(1, 0, 0, ">="));  // x1 >= 0
    constraints.push_back(std::make_tuple(0, 1, 0, ">="));  // x2 >= 0

    // Поиск оптимального значения целевой функции
    double optimalValue = (purpose == "min") ? std::numeric_limits<double>::max() : std::numeric_limits<double>::lowest();
    QPointF optimalPoint;

    // Находим пересечения
    QVector<QPointF> intersectionPoints;
    for (size_t i = 0; i < constraints.size(); ++i) {
        for (size_t j = i + 1; j < constraints.size(); ++j) {
            QPointF intersection;
            if (findIntersection(constraints[i], constraints[j], intersection)) {
                intersectionPoints.push_back(intersection);
            }
        }
    }

    // Проверка допустимых точек
    QVector<QPointF> feasiblePoints;
    for (const QPointF& point : intersectionPoints) {
        if (isFeasiblePoint(point)) {
            feasiblePoints.push_back(point);
        }
    }

    // Обработка случая, когда максимум или минимум не существует
    bool allAbove = true;  // Все точки выше текущего уровня целевой функции

    for (const QPointF& point : feasiblePoints) {
        double x = (point.x() - 50) * 10 / (500 * scaleFactor);
        double y = (550 - point.y()) * 10 / (500 * scaleFactor);
        double value = a * x + b * y;

        if ((purpose == "min" && value < optimalValue) || (purpose == "max" && value > optimalValue)) {
            optimalValue = value;
            optimalPoint = point;
        }
    }

    for (const QPointF& point : feasiblePoints) {
        double x = (point.x() - 50) * 10 / (500 * scaleFactor);
        double y = (550 - point.y()) * 10 / (500 * scaleFactor);
        double value = a * x + b * y;

        if (qFuzzyCompare(x, 0.0) || qFuzzyCompare(y, 0.0)) {
            continue;
        }

        const double epsilon = 1e-6;
        if (value < optimalValue + epsilon) {
            allAbove = false;
        }
    }

    // Обработка случая, когда максимум или минимум не существует
    if (purpose == "max" && allAbove) {
        hasSolution = false; // Обозначаем, что решения нет
        ui->ansLabel->setText("Максимум не существует.");
    } else if (purpose == "min") {
        ui->targetSlider->setMaximum(optimalValue * 5);
        ui->ansLabel->setText(QString("Оптимальное значение: F = %1").arg(optimalValue, 0, 'f', 1));
    } else {
        ui->targetSlider->setMaximum(optimalValue * 5);
        ui->ansLabel->setText(QString("Оптимальное значение: F = %1").arg(optimalValue, 0, 'f', 1));
    }

    if (feasiblePoints.isEmpty()) ui->ansLabel->setText("Решения нет");

    ui->targetSlider->setValue(optimalValue);
    ui->maxTargetLabel->setText(QString::number(ui->targetSlider->maximum()));
    // Перерисовка графика
    update();
}

void LpWidget::on_targetSlider_valueChanged(int value)
{
    ui->curTargetLabel->setText(QString::number(value));
    update();
}

void LpWidget::on_scaleSlider_valueChanged(int value)
{
    ui->curScaleLabel->setText(QString::number(value));
    scaleFactor = value;
    update();
}
