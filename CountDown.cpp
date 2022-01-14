#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QPainter>
#include <QMouseEvent>

class TransparentWidget : public QWidget
{
    Q_OBJECT
public:
    TransparentWidget(QWidget *parent = 0)
        : QWidget(parent)
    {
        setWindowTitle(QString::fromLocal8Bit("透明无边框窗口"));
        setFixedSize(480, 320);
        setWindowFlag(Qt::FramelessWindowHint);
        setAttribute(Qt::WA_TranslucentBackground);

        QPushButton *button = new QPushButton("Hello world!", this);
        button->setGeometry(5, 5, 80, 40);
    }

    void paintEvent(QPaintEvent *)
    {
        QPainter painter(this);
        painter.fillRect(this->rect(), QColor(0, 0, 0, 0x20)); /* 设置透明颜色 */
    }

    void mousePressEvent(QMouseEvent *event)
    {
        if (event->button() == Qt::LeftButton) {
            m_startPoint = frameGeometry().topLeft() - event->globalPos();
        }
    }

    void mouseMoveEvent(QMouseEvent *event)
    {
        this->move(event->globalPos() + m_startPoint);
    }

private:
    QPoint m_startPoint;
};
