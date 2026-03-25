#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class LcdClock;

/**
 * @brief Hauptfenster der Uhr-Anwendung.
 *
 * Das Fenster kapselt die Fensterinteraktion (Drag, Kontextmenü)
 * und delegiert die Uhr-Logik an die Komponente @ref LcdClock.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Erzeugt das Hauptfenster.
     * @param parent Optionales Parent-Widget.
     */
    explicit MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Zerstört das Hauptfenster und gibt UI-Ressourcen frei.
     */
    ~MainWindow() override;

private:
    Ui::MainWindow *_ui{nullptr};   ///< Zeiger auf das von Qt Designer erzeugte UI-Objekt.
    LcdClock *_lcd_clock{nullptr};  ///< Verantwortlich für die Anzeige- und Update-Logik der Uhr.
    QPoint _mouse_pos{};            ///< Letzte Mausposition relativ zum Fenster für Drag-Bewegungen.

private slots:
    /**
     * @brief Zeigt das Kontextmenü an der übergebenen Fensterposition.
     * @param pos Position relativ zum Hauptfenster.
     */
    void showContextMenu(const QPoint &pos);

protected:
    /**
     * @brief Verarbeitet das Loslassen einer Maustaste.
     * @param event Mausereignis.
     */
    void mouseReleaseEvent(QMouseEvent *event) override;
    
    /**
     * @brief Verarbeitet das Drücken einer Maustaste.
     * @param event Mausereignis.
     */
    
    void mousePressEvent(QMouseEvent *event) override;
    /**
     * @brief Verarbeitet Mausbewegungen zum Verschieben des Fensters.
     * @param event Mausereignis.
     */
    void mouseMoveEvent(QMouseEvent *event) override;
    
    /**
     * @brief Verarbeitet das Schließen des Fensters.
     * @param event Schließereignis.
     */
    void closeEvent(QCloseEvent *event) override;

};
#endif // MAIN_WINDOW_H
