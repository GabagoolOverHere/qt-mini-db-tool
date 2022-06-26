#ifndef TESTDB_LINENUMBERAREA_H
#define TESTDB_LINENUMBERAREA_H


#include <QWidget>
#include "codeeditor.h"

class LineNumberArea : public QWidget {
Q_OBJECT
public:
    explicit LineNumberArea(CodeEditor *editor) : QWidget(editor), code_editor(editor) {};

    QSize sizeHint() const override {
        return QSize(code_editor->LineNumberAreaWidth(), 0);
    }

protected:
    void paintEvent(QPaintEvent *event) override {
        code_editor->LineNumberAreaPaintEvent(event);
    }

private:
    CodeEditor *code_editor;
};


#endif
