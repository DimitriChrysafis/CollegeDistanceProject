#include "tripdialog.h"

/**
 * @brief Constructs a new TripDialog object.
 * @param parent Pointer to the parent widget.
 */
TripDialog::TripDialog(QWidget *parent): QDialog(parent)
{
    // Widgets declaration
    collegeName = new QLabel(this);
    storesHolder = new QStackedWidget(this);
    distToPrev = new QLabel(this);
    distToNext = new QLabel(this);
    previous = new QPushButton("Previous", this);
    next = new QPushButton("Next", this);
    QGridLayout* layout_ = new QGridLayout(this);
    tripOverview = new QLabel("Trip Over!!", this);

    collegeName->setStyleSheet("font-weight: bold; font-size: 15pt; text-decoration: underline");
    collegeName->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    connect(previous, &QPushButton::clicked, this, &TripDialog::on_button_previous_clicked);
    connect(next, &QPushButton::clicked, this, &TripDialog::on_button_next_clicked);

    layout_->addWidget(collegeName, 0, 0, 1, 2, Qt::AlignCenter);
    layout_->addWidget(storesHolder, 1, 0, 1, 2, Qt::AlignCenter);
    layout_->addWidget(distToPrev, 2, 0, Qt::AlignCenter);
    layout_->addWidget(distToNext, 2, 1, Qt::AlignCenter);
    layout_->addWidget(previous, 3, 0, Qt::AlignCenter);
    layout_->addWidget(next, 3, 1, Qt::AlignCenter);
}

/**
 * @brief Destroys the TripDialog object.
 */
TripDialog::~TripDialog()
{
}

/**
 * @brief Sets the vector of colleges for the trip.
 * @param vector Vector of College objects representing the trip colleges.
 */
void TripDialog::getColleges(QVector<College> vector)
{
    colleges = vector;
}

/**
 * @brief Sets the vector of distances between colleges.
 * @param vector Vector of integers representing the distances between colleges.
 */
void TripDialog::getDistances(QVector<int> vector)
{
    distances = vector;
}

/**
 * @brief Sets the souvenirs for each college.
 * @param souvenirs Map of souvenirs for each college.
 */
void TripDialog::getSouvenirs(const QMap<QString, QMap<QString, double>>& souvenirs) {
    for(auto& college: colleges) {
        CampusStore* newStore = new CampusStore(college.name(), this);
        for(auto [key, value]: souvenirs[college.name()].asKeyValueRange()) {
            newStore->addItem(key, "", value);
        }
        storesHolder->addWidget(newStore);
    }
    storesHolder->addWidget(tripOverview);
}

/**
 * @brief Displays the name of the college at the given index.
 * @param index The index of the college in the trip.
 */
void TripDialog::displayName(int index)
{
    collegeName->setText(colleges[index].name());
}

/**
 * @brief Displays the distance from the previous college at the given index.
 * @param index The index of the college in the trip.
 */
void TripDialog::displayPreviousDistance(int index)
{
    if (index >= 0 && index < distances.size()) {
        distToPrev->setText("Distance From Previous College: " + QString::number(distances[index]));
    } else
        distToPrev->setText("N/A");
}

/**
 * @brief Displays the distance to the next college at the given index.
 * @param index The index of the college in the trip.
 */
void TripDialog::displayNextDistance(int index)
{
    if (index >= 0 && index < distances.size()) {
        distToNext->setText("Distance To Next College: " + QString::number(distances[index]));
    } else
        distToNext->setText("N/A");
}

/**
 * @brief Handles the click event of the "Next" button.
 */
void TripDialog::on_button_next_clicked()
{
    index++;
    if (index == colleges.size())
    {
        next->setText("Finish");
        collegeName->setText("End of the Trip!");
        calculateTripDetails();
        distToPrev->setHidden(true);
        distToNext->setHidden(true);
    }
    else if (index > colleges.size())
    {
        close();
    }
    else
    {
        displayName(index);
        displayPreviousDistance(index - 1);
        displayNextDistance(index);
    }
    previous->setEnabled(true);
    storesHolder->setCurrentIndex(index);
}

/**
 * @brief Handles the click event of the "Previous" button.
 */
void TripDialog::on_button_previous_clicked()
{
    index--;
    if (index == 0)
        previous->setEnabled(false);
    if (index < colleges.size())
    {
        distToPrev->setHidden(false);
        distToNext->setHidden(false);
        next->setText("Next");
    }
    displayName(index);
    displayPreviousDistance(index - 1);
    displayNextDistance(index);

    storesHolder->setCurrentIndex(index);
}

/**
 * @brief Calculates and displays trip details.
 */
void TripDialog::calculateTripDetails() {
    int totalDistance = 0;
    for(auto& dist: distances)
        totalDistance += dist;

    double totalSpend = 0;

    QString details = "Total Distance: " + QString::number(totalDistance) + "\n";

    for(int i = 0; i < storesHolder->count() - 1; ++i) {
        details.append(qobject_cast<CampusStore*>(storesHolder->widget(i))->getCartInfo());
        totalSpend += qobject_cast<CampusStore*>(storesHolder->widget(i))->getCartTotal();
    }

    details.append("Total Spent: " + QString::number(totalSpend));

    tripOverview->setText(details);
}

/**
 * @brief Resets the trip dialog to its initial state.
 */
void TripDialog::reset()
{
    index = 0;
    next->setText("Next");
    next->setEnabled(true);
    previous->setEnabled(false);
    distToPrev->setHidden(false);
    distToNext->setHidden(false);

    storesHolder->removeWidget(tripOverview);
    for(int i = storesHolder->count() - 1; i >= 0; --i) {
        QWidget* widge = storesHolder->widget(i);
        storesHolder->removeWidget(widge);
        widge->deleteLater();
    }
}
