#ifndef TESTDB_CODEEDITOR_H
#define TESTDB_CODEEDITOR_H


#include <QPlainTextEdit>

class CodeEditor : public QPlainTextEdit {
Q_OBJECT
public:
    explicit CodeEditor(QWidget *parent = nullptr);

    void LineNumberAreaPaintEvent(QPaintEvent *event);

    int LineNumberAreaWidth();

protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:

    void UpdateLineNumberAreaWidth(const int &init);

    void HighlightCurrentLine();

    void UpdateLineNumberArea(const QRect &rect, const int &dy);

private:
    QWidget *line_number_area;
};


#endif
