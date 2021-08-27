#ifndef QWIDGET_H
#define QWIDGET_H

#include <QWidget>

namespace Ui {
class QWidget;
}

class QWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QWidget(QWidget *parent = nullptr);
    ~QWidget();

private:
    Ui::QWidget *ui;
};

#endif // QWIDGET_H
