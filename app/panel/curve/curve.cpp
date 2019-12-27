#include "curve.h"

CurvePanel::CurvePanel(QWidget *parent) :
  PanelWidget(parent)
{
  // FIXME: This won't work if there's ever more than one of this panel
  setObjectName("CurvePanel");

  // Create main widget and set it
  widget_ = new CurveWidget();
  setWidget(widget_);

  // Set strings
  Retranslate();
}

void CurvePanel::changeEvent(QEvent *e)
{
  if (e->type() == QEvent::LanguageChange) {
    Retranslate();
  }
  PanelWidget::changeEvent(e);
}

void CurvePanel::Retranslate()
{
  SetTitle(tr("Curve Editor"));
}