#pragma once

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class dialog; }
QT_END_NAMESPACE

class dialog : public QDialog
{
   Q_OBJECT

public:
   explicit dialog (QWidget* parent = nullptr);

   ~dialog () override;

private:
   Ui::dialog* ui;
};

