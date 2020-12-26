#include "../include/library/header.h"

#include <QApplication>
#include <QPushButton>

#include "internal.h"
#include "dialog.h"

namespace library
{

double sum(double a, double b)
{
   return internal::sum_implementation(a, b);
}

int run_main(int argc, char ** argv)
{
   QApplication app (argc, argv);
   dialog dlg;
   dlg.show();
   return app.exec();
}

}
