#include "customgraphicsview.h"
#include <QDebug>
CustomGraphicsView::CustomGraphicsView(QWidget *parent):
    QGraphicsView(parent)
{
    setColor(Qt::black);
    setItemWidth(0);
    setLinePixelSize(1);
    m_pointA = 0;
    m_pointB = 0;
}

CustomGraphicsView::~CustomGraphicsView()
{

}

void CustomGraphicsView::setItemWidth(int width)
{
    m_itemWidth = width;
}

void CustomGraphicsView::setColor(QColor color)
{
    m_color = color;
}

void CustomGraphicsView::setLinePixelSize(int value)
{
    m_linePixelSize = value;
}

void CustomGraphicsView::resizeEvent(QResizeEvent *event)
{
    QGraphicsView::resizeEvent(event);
    if(m_itemWidth >= 0)
    {
        getSector();

        double nearPoint = ((double)1)/this->width();
        double a = m_pointA + nearPoint;
        double b = m_pointB - nearPoint;

        qDebug()<<"border-top :" + QString::number(m_linePixelSize) + "px solid; border-top-color :qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 transparent, stop: " + QString::number(m_pointA) + " transparent, stop:" + QString::number(a) + " " + m_color.name() + ", stop:" +  QString::number(b) + " " + m_color.name()  + ", stop:" +  QString::number(m_pointB) + " transparent, stop:1 transparent);";
        this->setStyleSheet("border-top :" + QString::number(m_linePixelSize) + "px solid; border-top-color :qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 transparent, stop: " + QString::number(m_pointA) + " transparent, stop:" + QString::number(a) + " " + m_color.name() + ", stop:" +  QString::number(b) + " " + m_color.name()  + ", stop:" +  QString::number(m_pointB) + " transparent, stop:1 transparent);");
    }
}

void CustomGraphicsView::getSector()
{
    if(m_itemWidth >= 0)
    {
        double delta = (double)m_itemWidth/2;
        double sectorPoint = delta/this->width();

        m_pointA = sectorPoint;
        m_pointB = 1 - sectorPoint;
    }
}
