#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

/**
 * @brief Hauptfenster der Uhr-Anwendung.
 *
 * Das Fenster zeigt die aktuelle Uhrzeit in einem LCD-Widget an,
 * unterstützt Drag-and-Drop-Verschieben per Maus und bietet ein
 * Kontextmenü mit einer Beenden-Aktion.
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
    /** @brief Zeiger auf das von Qt Designer erzeugte UI-Objekt. */
    Ui::MainWindow *_ui{nullptr};
    /** @brief Letzte Mausposition relativ zum Fenster für Drag-Bewegungen. */
    QPoint _mouse_pos{};

private slots:
    /** @brief Aktualisiert die angezeigte Uhrzeit im LCD-Widget. */
    void updateTime();
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
