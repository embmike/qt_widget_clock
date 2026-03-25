/**
 * @file lcd_clock.h
 * @brief Deklaration der Logikkomponente für die LCD-Uhr.
 */
#ifndef LCD_CLOCK_H
#define LCD_CLOCK_H

#include <QObject>

class QLCDNumber;
class QTimer;

/**
 * @brief Kapselt die Update-Logik für eine LCD-Zeitanzeige.
 *
 * Die Klasse aktualisiert ein übergebenes @c QLCDNumber zyklisch und trennt
 * so die Uhr-Logik von der Fenster-Interaktionslogik.
 */
class LcdClock : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief Erstellt die Logik für die übergebene LCD-Anzeige.
     * @param display Zielanzeige.
     * @param parent Optionales Parent-Objekt.
     */
    explicit LcdClock(QLCDNumber *display, QObject *parent = nullptr);

private slots:
    /** @brief Aktualisiert die Zeitdarstellung (blinkender Doppelpunkt). */
    void updateDisplay();

private:
    /** @brief Referenz auf die zu aktualisierende LCD-Anzeige. */
    QLCDNumber *_display{nullptr};
    /** @brief Taktgeber für periodische Aktualisierungen. */
    QTimer *_timer{nullptr};
};

#endif // LCD_CLOCK_H
