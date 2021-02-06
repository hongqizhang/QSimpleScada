#ifndef VOBJECT_H
#define VOBJECT_H

#include "qscadaobjectinfo.h"

#include <QWidget>
#include <QLabel>
#include <QImage>

class QGraphicsDropShadowEffect;

class QScadaObject : public QWidget
{
    Q_OBJECT
public:
    explicit QScadaObject(QWidget *parent = nullptr);
    QScadaObject(QScadaObjectInfo *, QWidget *parent = nullptr);
    ~QScadaObject();

    void setGeometry(int x, int y, int width, int height);
    void setGeometry(const QRect &);
    QRect geometry();

    QScadaObjectInfo *info() const;
    void setInfo(QScadaObjectInfo *info);

    bool selected() const;
    void setSelected(bool selected);

    bool isEditable() const;
    void setIsEditable(bool isEditable);

    virtual void update();
    virtual void setProperty(char*, QVariant) = 0;
    virtual void updateValue(QVariant) = 0;
    virtual void updateUIProperties() = 0;

private:
    QScadaObjectAction action() const;
    void setAction(const QScadaObjectAction &action);

    void move(int x, int y);

    void initUI();

protected:
    virtual void resize(int x, int y);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent*);

    void paintEvent(QPaintEvent *e);

signals:
    void objectSelected(int id);
    void objectDoubleClicked(QScadaObject*);
    void objectMove(int x, int y);
    void objectResize(int x, int y);

private:
    QPoint mPosition;
    bool mIsEditable;//if tru object could be moveable, if false it's static

    QScadaObjectAction mAction;
    QScadaObjectInfo *mInfo;
    QGraphicsDropShadowEffect* mEffect;
    bool mSelected;
};

#endif // VOBJECT_H
