/**
 * @file clock_settings_model.h
 * @brief Modell für persistente Anzeigeeinstellungen der LCD-Uhr.
 */
#ifndef CLOCK_SETTINGS_MODEL_H
#define CLOCK_SETTINGS_MODEL_H

#include <QObject>
#include <QMap>
#include <QString>
#include <QColor>

/**
 * @brief Modell zur Verwaltung der auswählbaren Uhrfarben.
 *
 * @details Die Klasse persistiert die ausgewählte Farbe über @c QSettings und stellt
 * Änderungsbenachrichtigungen für Controller/View bereit.
 */
class ClockSettingsModel : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief Verfügbare Farbschemata für die LCD-Anzeige.
     */
    enum struct ClockColor
    {
        Undefined,
        White,
        Green,
        Red,
        Dark_Blue,
        Black,
    };
    Q_ENUM(ClockColor)

    /**
     * @brief Erzeugt das Einstellungsmodell und lädt gespeicherte Werte.
     * @param parent Optionales Parent-Objekt.
     */
    explicit ClockSettingsModel(QObject *parent = nullptr);

    /**
     * @brief Liefert die aktuell gesetzte Uhrfarbe.
     * @return Aktuelle Farbauswahl.
     */
    ClockColor color() const;

    /**
     * @brief Setzt eine neue Uhrfarbe und persistiert diese.
     * @param color Neue Farbauswahl.
     */
    void setColor(ClockColor color);

    QColor getQColor(ClockColor color);

signals:
    /**
     * @brief Signalisiert eine geänderte Uhrfarbe.
     * @param color Neu gesetzte Farbauswahl.
     */
    void colorChanged(ClockColor color);

private:
    /** @brief Lädt die persistierte Farbauswahl aus den Einstellungen. */
    void load();

    /** @brief Schreibt die Farbauswahl in die Einstellungen. */
    void save() const;

    /** @brief Mappe der Farben bezüglich ClockColor. */
    static const QMap<ClockColor, QColor> _color_map;

    /** @brief Aktuell selektierte Farbauswahl. */
    ClockColor _color{ClockColor::Black};

    /** @brief Name der Farbeinstellung */
    static constexpr auto _color_key{"clock_color"};
};

#endif // CLOCK_SETTINGS_MODEL_H
