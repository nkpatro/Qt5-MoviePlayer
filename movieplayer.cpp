#include "movieplayer.hpp"
#include "ui_movieplayer.h"

MoviePlayer::MoviePlayer(QWidget *parent) : QMainWindow(parent), ui(new Ui::MoviePlayer) {

    ui->setupUi(this);

    video = NULL;
}


MoviePlayer::~MoviePlayer() {

    delete ui;

    if (video) {
        delete video;
        video = NULL;
    }
}


void MoviePlayer::limpiarVideo() {

    if (video) {
        delete video;
        video = NULL;
    }

    this->setWindowTitle(WINDOW_TITLE);
    activarFuncionalidades(false);
}


void MoviePlayer::activarFuncionalidades(bool cond) {

    ui->actionGuardarComo->setEnabled(cond);
    ui->actionCerrar->setEnabled(cond);
    ui->actionAbrirCon->setEnabled(cond);
    ui->actionAbrirDirectorio->setEnabled(cond);
    ui->actionAbrirTerminal->setEnabled(cond);
    ui->actionRenombrar->setEnabled(cond);
    ui->actionEliminar->setEnabled(cond);
    ui->buttonCerrar->setEnabled(cond);
    ui->buttonPlay->setEnabled(cond);
    ui->buttonPausa->setEnabled(cond);
    ui->buttonStop->setEnabled(cond);
}


// ARCHIVO

void MoviePlayer::on_actionAbrir_triggered() {

    QString ruta = QFileDialog::getOpenFileName(this, tr("Abrir vídeo"), QString(),
                                                tr("Todos los archivos (*);;"));


    if (!ruta.isEmpty()) {

        QFile file(ruta);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr(WINDOW_CRITICAL), tr("No se puede abrir el vídeo."));
            return;
        }

        //Borrar video anterior
        limpiarVideo();

        //Cargar video
        video = new QMovie(ruta);
        ui->labelVideo->setMovie(video);
        video->start();

        //Ajustes
        //this->setWindowTitle(imagen->name() + " - Visor de Imágenes");
        activarFuncionalidades(true);
    }

}


void MoviePlayer::on_actionAbrirRecientes_triggered() { }
void MoviePlayer::on_actionGuardarComo_triggered() { }
void MoviePlayer::on_actionCerrar_triggered() { }
void MoviePlayer::on_actionSalir_triggered() { }
