#ifndef CUSTOMGRAPHICSVIEW_H
#define CUSTOMGRAPHICSVIEW_H
#include <QGraphicsView>
class CustomGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit CustomGraphicsView(QWidget *parent = 0);
    ~CustomGraphicsView();
    void setItemWidth(int);
    void setColor(QColor);
    void setLinePixelSize(int);
private:
    int m_itemWidth;
    int m_linePixelSize;
    double m_pointA, m_pointB;
    QColor m_color;
    void resizeEvent(QResizeEvent *event) override;
    void getSector();
};

#endif // CUSTOMGRAPHICSVIEW_H
