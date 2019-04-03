#include "timelinelabel.h"

#include <QHBoxLayout>
#include <QPushButton>
#include <QInputDialog>

TimelineLabel::TimelineLabel() :
  track_(nullptr)
{
  QHBoxLayout* layout = new QHBoxLayout(this);
  layout->setMargin(0);
  layout->setSpacing(layout->spacing()/2);

  label_ = new ClickableLabel();
  layout->addWidget(label_);
  connect(label_, SIGNAL(double_clicked()), this, SLOT(RenameTrack()));

  mute_button_ = new QPushButton("M");
  QSize fixed_size(mute_button_->sizeHint().height(), mute_button_->sizeHint().height());
  fixed_size *= 0.75;
  mute_button_->setFixedSize(fixed_size);
  mute_button_->setStyleSheet("QPushButton::checked { background: red; }");
  mute_button_->setCheckable(true);
  layout->addWidget(mute_button_);

  solo_button_ = new QPushButton("S");
  solo_button_->setFixedSize(fixed_size);
  solo_button_->setStyleSheet("QPushButton::checked { background: yellow; }");
  solo_button_->setCheckable(true);
  layout->addWidget(solo_button_);

  lock_button_ = new QPushButton("L");
  lock_button_->setFixedSize(fixed_size);
  lock_button_->setStyleSheet("QPushButton::checked { background: gray; }");
  lock_button_->setCheckable(true);
  layout->addWidget(lock_button_);
}

void TimelineLabel::SetTrack(Track *track)
{
  if (track_ != nullptr) {
    disconnect(mute_button_, SIGNAL(toggled(bool)), track_, SLOT(SetMuted(bool)));
    disconnect(solo_button_, SIGNAL(toggled(bool)), track_, SLOT(SetSoloed(bool)));
    disconnect(lock_button_, SIGNAL(toggled(bool)), track_, SLOT(SetLocked(bool)));
  }

  track_ = track;

  if (track_ != nullptr) {
    UpdateState();

    connect(mute_button_, SIGNAL(toggled(bool)), track_, SLOT(SetMuted(bool)));
    connect(solo_button_, SIGNAL(toggled(bool)), track_, SLOT(SetSoloed(bool)));
    connect(lock_button_, SIGNAL(toggled(bool)), track_, SLOT(SetLocked(bool)));
  }
}

void TimelineLabel::UpdateState()
{
  label_->setText(track_->name());

  mute_button_->setChecked(track_->IsMuted());
  solo_button_->setChecked(track_->IsSoloed());
  lock_button_->setChecked(track_->IsLocked());
}

void TimelineLabel::RenameTrack()
{
  bool ok;
  QString new_name = QInputDialog::getText(this,
                                           tr("Rename Track"),
                                           tr("Enter the new name for this track"),
                                           QLineEdit::Normal,
                                           track_->name(),
                                           &ok);
  if (ok) {
    track_->SetName(new_name);

    UpdateState();
  }
}
