#ifndef LPWIDGET_H
#define LPWIDGET_H

#include <QLineEdit>
#include <QComboBox>
#include <QWidget>
#include <tuple>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class LpWidget; }
QT_END_NAMESPACE

class LpWidget : public QWidget {
    Q_OBJECT

public:
    explicit LpWidget(QWidget *parent = nullptr);
    ~LpWidget();

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void solveAndDraw();

    void on_targetSlider_valueChanged(int value);

    void on_scaleSlider_valueChanged(int value);

private:
    Ui::LpWidget *ui;
    std::vector<std::tuple<double, double, double, QString>> constraints;

    double a, b;
    bool hasSolution;
    double scaleFactor = 1.0;

    bool isFeasiblePoint(const QPointF& point);
    void sortPointsClockwise(QVector<QPointF>& points);
    bool isPointValid(const QPointF& point);
    bool findIntersection(const std::tuple<double, double, double, QString>& line1,
                          const std::tuple<double, double, double, QString>& line2, QPointF& intersection);
    void parseConstraint(QLineEdit *editX1, QLineEdit *editX2, QComboBox *signBox, QLineEdit *editValue);
};

#endif // LPWIDGET_H
