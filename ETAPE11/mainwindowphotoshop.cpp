#include "mainwindowphotoshop.h"
#include "ui_mainwindowphotoshop.h"

#include <QMessageBox>
#include <QInputDialog>
#include <QFileDialog>
#include <QScreen>
#include <QRect>
#include <QPixmap>
#include <QColorDialog>


#include "ImageNG.h"
#include "ImageRGB.h"
#include "ImageB.h"
#include "PhotoShop.h"
#include "Iterateur.h"
#include "Traitements.h"
#include "XYException.h"

MainWindowPhotoShop::MainWindowPhotoShop(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindowPhotoShop)
{
    ui->setupUi(this);
    setTitre("Mini-PhotoShop  en C++");

    // Centrage de la fenetre
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->availableGeometry();
    int x = (screenGeometry.width() - width()) / 2;
    int y = (screenGeometry.height() - height()) / 2;
    move(x, y);
    setFixedSize(1021,845);

    // Configuration de la table des images
    ui->tableWidgetImages->setColumnCount(4);
    ui->tableWidgetImages->setRowCount(0);
    QStringList labelsTableOptions;
    labelsTableOptions << "Id" << "Type" << "Dimension" << "Nom";
    ui->tableWidgetImages->setHorizontalHeaderLabels(labelsTableOptions);
    ui->tableWidgetImages->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidgetImages->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetImages->horizontalHeader()->setVisible(true);
    ui->tableWidgetImages->horizontalHeader()->setDefaultSectionSize(100);
    ui->tableWidgetImages->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidgetImages->verticalHeader()->setVisible(false);
    ui->tableWidgetImages->horizontalHeader()->setStyleSheet("background-color: lightyellow");

    // Intialisation des scrollArea
    
    setImageNG("selection");
    setImageNG("operande1");
    setImageNG("operande2");
    setImageNG("resultat");
    

    // ComboBox des traitements disponibles
    ajouteTraitementDisponible("Eclaircir (+ val)");
    ajouteTraitementDisponible("Eclaircir (++)");
    ajouteTraitementDisponible("Assombrir (- val)");
    ajouteTraitementDisponible("Assombrir (--)");
    ajouteTraitementDisponible("Différence");
    ajouteTraitementDisponible("Comparaison (==)");
    ajouteTraitementDisponible("Comparaison (<)");
    ajouteTraitementDisponible("Comparaison (>)");
    ajouteTraitementDisponible("Seuillage");
    ajouteTraitementDisponible("Filtre moyenneur");
    ajouteTraitementDisponible("Filtre médian");
    ajouteTraitementDisponible("Erosion");
    ajouteTraitementDisponible("Dilatation");
    ajouteTraitementDisponible("Négatif");

    // Etape 14 (TO DO)
    // Restauration bibliothèque via fichier de sauvegarde

    // TESTS DEMOS A SUPPRIMER
    //ajouteTupleTableImages(3,"NG","256x256","lena.bmp");
    setResultatBoolean(1);
}

MainWindowPhotoShop::~MainWindowPhotoShop()
{
    delete ui;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Méthodes de la fenêtre (ne pas modifier) ///////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::setTitre(string titre)
{
  this->setWindowTitle(titre.c_str());
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::setNomImage(string nom)
{
  ui->lineEditNom->setText(QString::fromStdString(nom));
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
string MainWindowPhotoShop::getNomImage() const
{
  return ui->lineEditNom->text().toStdString();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::setParametresImageNG(int max,int min,int luminance,float contraste)
{
  if (max == -1)
  {
    ui->lineEditMax->setText("");
    ui->lineEditMin->setText("");
    ui->lineEditLuminance->setText("");
    ui->lineEditContraste->setText("");
    return;
  }
  char tmp[20];
  sprintf(tmp,"%d",max);
  ui->lineEditMax->setText(tmp);
  sprintf(tmp,"%d",min);
  ui->lineEditMin->setText(tmp);
  sprintf(tmp,"%d",luminance);
  ui->lineEditLuminance->setText(tmp);
  sprintf(tmp,"%f",contraste);
  ui->lineEditContraste->setText(tmp);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void MainWindowPhotoShop::setImageNG(string destination,const ImageNG* imageng)
{
    QPixmap * pixmap = NULL;
    if (imageng != NULL)
    {
      // Creation du QPixmap
      int largeur = imageng->getDimension().getLargeur();
      int hauteur = imageng->getDimension().getHauteur();
      QImage im1(largeur,hauteur,QImage::Format_RGB32);
      for(int x=0 ; x<largeur ; x++)
        for(int y=0 ; y<hauteur ; y++)
        {
          int valeur = imageng->getPixel(x,y);
          im1.setPixel(x,y,qRgb(valeur,valeur,valeur));
        }
     pixmap = new QPixmap(QPixmap::fromImage(im1));
    }

    // Mise en place du QPixmap
    QLabel* label = new QLabel();
    label->setAlignment(Qt::AlignCenter);
    if (pixmap) label->setPixmap(*pixmap);
    else label->setText("vide");
    if (destination == "selection") ui->scrollAreaSelection->setWidget(label);
    if (destination == "operande1") ui->scrollAreaOperande1->setWidget(label);
    if (destination == "operande2") ui->scrollAreaOperande2->setWidget(label);
    if (destination == "resultat") ui->scrollAreaResultat->setWidget(label);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void MainWindowPhotoShop::setImageRGB(string destination,const ImageRGB* imagergb)
{
    QPixmap * pixmap = NULL;
    if (imagergb != NULL)
    {
      // Creation du QPixmap
      int largeur = imagergb->getDimension().getLargeur();
      int hauteur = imagergb->getDimension().getHauteur();
      QImage im1(largeur,hauteur,QImage::Format_RGB32);
      for(int x=0 ; x<largeur ; x++)
        for(int y=0 ; y<hauteur ; y++)
        {
          Couleur valeur = imagergb->getPixel(x,y);
          im1.setPixel(x,y,qRgb(valeur.getRouge(),valeur.getVert(),valeur.getBleu()));
        }
     pixmap = new QPixmap(QPixmap::fromImage(im1));
    }

    // Mise en place du QPixmap
    QLabel* label = new QLabel();
    label->setAlignment(Qt::AlignCenter);
    if (pixmap) label->setPixmap(*pixmap);
    else label->setText("vide");
    if (destination == "selection") ui->scrollAreaSelection->setWidget(label);
    if (destination == "operande1") ui->scrollAreaOperande1->setWidget(label);
    if (destination == "operande2") ui->scrollAreaOperande2->setWidget(label);
    if (destination == "resultat") ui->scrollAreaResultat->setWidget(label);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void MainWindowPhotoShop::setImageB(string destination,const ImageB* imageb)
{
    QPixmap * pixmap = NULL;
    if (imageb != NULL)
    {
      // Creation du QPixmap
      int largeur = imageb->getDimension().getLargeur();
      int hauteur = imageb->getDimension().getHauteur();
      QImage im1(largeur,hauteur,QImage::Format_RGB32);
      for(int x=0 ; x<largeur ; x++)
        for(int y=0 ; y<hauteur ; y++)
        {
          bool valeur = imageb->getPixel(x,y);
          if (valeur) im1.setPixel(x,y,qRgb(ImageB::couleurTrue.getRouge(),ImageB::couleurTrue.getVert(),ImageB::couleurTrue.getBleu()));
          else im1.setPixel(x,y,qRgb(ImageB::couleurFalse.getRouge(),ImageB::couleurFalse.getVert(),ImageB::couleurFalse.getBleu()));
        }
     pixmap = new QPixmap(QPixmap::fromImage(im1));
    }

    // Mise en place du QPixmap
    QLabel* label = new QLabel();
    label->setAlignment(Qt::AlignCenter);
    if (pixmap) label->setPixmap(*pixmap);
    else label->setText("vide");
    if (destination == "selection") ui->scrollAreaSelection->setWidget(label);
    if (destination == "operande1") ui->scrollAreaOperande1->setWidget(label);
    if (destination == "operande2") ui->scrollAreaOperande2->setWidget(label);
    if (destination == "resultat") ui->scrollAreaResultat->setWidget(label);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::setResultatBoolean(int val)
{
  if (val == 1) // vrai
  {
    ui->checkBoxResultat->setChecked(true);
    ui->checkBoxResultat->setText("VRAI");
    ui->checkBoxResultat->setStyleSheet("background-color: lightgreen;border: 1px solid black;");
    return;
  }
  if (val == 0) // faux
  {
    ui->checkBoxResultat->setChecked(false);
    ui->checkBoxResultat->setText("FAUX");
    ui->checkBoxResultat->setStyleSheet("background-color: red;border: 1px solid black;");
    return;
  }
  // ni vrai, ni faux
  ui->checkBoxResultat->setChecked(false);
  ui->checkBoxResultat->setText("Résultat");
  ui->checkBoxResultat->setStyleSheet("background-color: lightyellow;border: 1px solid black;");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions utiles Table des Images (ne pas modifier) ////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::ajouteTupleTableImages(int id,string type,string dimension,string nom)
{
    char Id[20];
    sprintf(Id,"%d",id);

    char Type[20];
    strcpy(Type,type.c_str());

    char Dimension[20];
    strcpy(Dimension,dimension.c_str());

    char Nom[80];
    strcpy(Nom,nom.c_str());

    // Ajout possible
    int nbLignes = ui->tableWidgetImages->rowCount();
    nbLignes++;
    ui->tableWidgetImages->setRowCount(nbLignes);
    ui->tableWidgetImages->setRowHeight(nbLignes-1,20);

    QTableWidgetItem *item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setTextAlignment(Qt::AlignCenter);
    item->setText(Id);
    ui->tableWidgetImages->setItem(nbLignes-1,0,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setTextAlignment(Qt::AlignCenter);
    item->setText(Type);
    ui->tableWidgetImages->setItem(nbLignes-1,1,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setTextAlignment(Qt::AlignCenter);
    item->setText(Dimension);
    ui->tableWidgetImages->setItem(nbLignes-1,2,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setText(Nom);
    ui->tableWidgetImages->setItem(nbLignes-1,3,item);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::videTableImages()
{
    ui->tableWidgetImages->setRowCount(0);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int MainWindowPhotoShop::getIndiceImageSelectionnee()
{
    QModelIndexList liste = ui->tableWidgetImages->selectionModel()->selectedRows();
    if (liste.size() == 0) return -1;
    QModelIndex index = liste.at(0);
    int indice = index.row();
    return indice;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Combox des traitements disponibles (ne pas modifier) ///////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::ajouteTraitementDisponible(string operation)
{
    ui->comboBoxTraitements->addItem(operation.c_str());
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::videTraitementsDisponibles()
{
    ui->comboBoxTraitements->clear();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
string MainWindowPhotoShop::getTraitementSelectionne() const
{
    return ui->comboBoxTraitements->currentText().toStdString();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions permettant d'afficher des boites de dialogue (ne pas modifier) ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::dialogueMessage(const char* titre,const char* message)
{
   QMessageBox::information(this,titre,message);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::dialogueErreur(const char* titre,const char* message)
{
   QMessageBox::critical(this,titre,message);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
string MainWindowPhotoShop::dialogueDemandeTexte(const char* titre,const char* question)
{
    QString chaine = QInputDialog::getText(this,titre,question);
    return chaine.toStdString();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int MainWindowPhotoShop::dialogueDemandeInt(const char* titre,const char* question)
{
    return QInputDialog::getInt(this,titre,question);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
float MainWindowPhotoShop::dialogueDemandeFloat(const char* titre,const char* question)
{
    return QInputDialog::getDouble(this,titre,question);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
string MainWindowPhotoShop::dialogueDemandeFichierOuvrir(const char* question)
{
  QString fileName = QFileDialog::getOpenFileName(this,question, "", "Tous les fichiers (*.*)");
  return fileName.toStdString();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
string MainWindowPhotoShop::dialogueDemandeFichierEnregistrer(const char* question)
{
  QString fileName = QFileDialog::getSaveFileName(this,question, "", "Tous les fichiers (*.*)");
  return fileName.toStdString();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::dialogueDemandeCouleur(const char* message,int* pRouge,int* pVert,int* pBleu)
{
  QColor color = QColorDialog::getColor(Qt::red,this,message);
  *pRouge = color.red();
  *pVert = color.green();
  *pBleu = color.blue();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Clic sur la croix de la fenêtre ////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::closeEvent(QCloseEvent *event)
{
  if (event == NULL) {} // pour éviter le warning à la compilation
  // Etape 14 (TO DO)

  QApplication::exit();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions clics sur les items de menu //////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_actionQuitter_triggered()
{
  // Etape 14 (TO DO)

  QApplication::exit();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_actionCharger_ImageNB_triggered()
{
  // Etape 11 (TO DO)
  string nomF= dialogueDemandeFichierOuvrir("Quel est le nom du fichier de l'imageNB à charger ?");
  if(nomF.compare("")==0){
      dialogueErreur("Erreur","Nom de fichier vide");
      return;
  }
  else 
  {
    ImageNG *img= new ImageNG(nomF.c_str());
    if(img==NULL){
        dialogueErreur("Erreur","Image non chargée");
        return;
    }
    else
    {
      PhotoShop::getInstance().ajouteImage(img);
      videTableImages();
      Iterateur<Image*> it( *(PhotoShop::getInstance().getImages()));
      while(!it.end())
      {
          Image* img=(Image*)it;
          if( dynamic_cast<ImageNG*>(img) !=NULL)
          {
            ajouteTupleTableImages(img->getId(),"NG",to_string(img->getDimension().getHauteur())+ 'x'+ to_string(img->getDimension().getLargeur()),img->getNom());
          }
          else
          {
            ajouteTupleTableImages(img->getId(),"RGB",to_string(img->getDimension().getHauteur())+ 'x'+ to_string(img->getDimension().getLargeur()),img->getNom());
          }        
          it++;
      }
    }
  }
  dialogueMessage("Succès","ImageNG chargée");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_actionCharger_ImageRGB_triggered()
{
  // Etape 11 (TO DO)
  string nomF= dialogueDemandeFichierOuvrir("Quel est le nom du fichier de l'imageRGB à charger ?");
  if(nomF.compare("")==0){dialogueErreur("Erreur","Nom de fichier vide");return;}
  else 
  {
    ImageRGB *img= new ImageRGB(nomF.c_str());
    if(img==NULL){dialogueErreur("Erreur","Image non chargée");return;}
    else
    {
      cout<< endl<<"Nom image: "<<img->getNom( );// a modifier car il prend tout le path au lieu du nom
      PhotoShop::getInstance().ajouteImage(img);
      videTableImages();
      Iterateur<Image*> it( *(PhotoShop::getInstance().getImages()));
      while(!it.end())
      {
        Image* img=(Image*)it;
        if(dynamic_cast<ImageRGB*>(img)!=NULL)
        {
          ajouteTupleTableImages(img->getId(),"RGB",to_string(img->getDimension().getHauteur())+ 'x'+ to_string(img->getDimension().getLargeur()),img->getNom());
        }
        else
        {
          ajouteTupleTableImages(img->getId(),"NG",to_string(img->getDimension().getHauteur())+ 'x'+ to_string(img->getDimension().getLargeur()),img->getNom());
        }  
        it++;
      }
    }
  }
  dialogueMessage("Succès","ImageRGB chargée");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_actionEnregistrer_ImageNB_triggered()
{
  // Etape 11 (TO DO)
  int indice = getIndiceImageSelectionnee();
  if (indice== -1){dialogueErreur("Erreur","Aucune image selectionnée");return;}
  else
  {
    if( dynamic_cast<ImageNG*>(PhotoShop::getInstance().getImageParIndice(indice)) == NULL ){dialogueErreur("Erreur","Image non NG");return;} 
    Image* img= PhotoShop::getInstance().getImageParIndice(indice);
    if(img==NULL){dialogueErreur("Erreur","Image non chargée");return;}
    else
    {
      string nomF= dialogueDemandeFichierEnregistrer("Quel est le nom du fichier de l'imageNG à enregistrer ?");
      if(nomF.compare("")==0){dialogueErreur("Erreur","Nom de fichier vide");return;}
      else 
      {
        ImageNG* imgNG= (ImageNG*)img;//downcasting 
        string format= dialogueDemandeTexte("Format","Quel est le format de l'image à enregistrer ?\n tapper 1=JPG, 2=BMP, 3=PNG)");
        if(format.compare("")==0 ){dialogueErreur("Erreur","Format de fichier vide");return;}
        else if (format == "1") {format = "jpg";} 
        else if (format == "2") {format = "bmp";}
        else if (format == "3") {format = "png";} 
        else {dialogueErreur("Erreur", "Format de fichier invalide");return;}
        nomF.append("."+format);
        imgNG->exportToFile(nomF.c_str(),format.c_str());
      }
    }
  }
  dialogueMessage("Succès","ImageNG enregistrée");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_actionEnregistrer_ImageRGB_triggered()
{
  // Etape 11 (TO DO)
  int indice = getIndiceImageSelectionnee();
  if (indice== -1){dialogueErreur("Erreur","Aucune image selectionnée");return;}
  else
  {
    if( dynamic_cast<ImageRGB*>(PhotoShop::getInstance().getImageParIndice(indice)) == NULL ){dialogueErreur("Erreur","Image non RGB");return;} 
    Image* img= PhotoShop::getInstance().getImageParIndice(indice);
    if(img==NULL){dialogueErreur("Erreur","Image non chargée");return;}
    else
    {
      string nomF= dialogueDemandeFichierEnregistrer("Quel est le nom du fichier de l'imageRGB à enregistrer ?");
      if(nomF.compare("")==0){dialogueErreur("Erreur","Nom de fichier vide");return;}
      else 
      {
        ImageRGB* imgRGB= (ImageRGB*)img;//downcasting 
        string format= dialogueDemandeTexte("Format","Quel est le format de l'image à enregistrer ?\n tapper 1=JPG, 2=BMP, 3=PNG)");
        if(format.compare("")==0 ){dialogueErreur("Erreur","Format de fichier vide");return;}
        else if (format == "1") {format = "jpg";} 
        else if (format == "2") {format = "bmp";}
        else if (format == "3") {format = "png";} 
        else {dialogueErreur("Erreur", "Format de fichier invalide");return;}
        nomF.append("."+format);
        imgRGB->exportToFile(nomF.c_str(),format.c_str());
      }
    }
  }
  dialogueMessage("Succès","ImageRGB enregistrée");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_actionEnregistrer_ImageB_triggered()
{
  // Etape 11 (TO DO)
  int indice = getIndiceImageSelectionnee();
  if (indice== -1){dialogueErreur("Erreur","Aucune image selectionnée");return;}
  else
  {
    ImageB* imgB= dynamic_cast<ImageB*>(PhotoShop::getInstance().getImageParIndice(indice));
    if(imgB  == NULL ){dialogueErreur("Erreur","Image non B");return;} 
    else
    {
      string nomF= dialogueDemandeFichierEnregistrer("Quel est le nom du fichier de l'imageB à enregistrer ?");
      if(nomF.compare("")==0){dialogueErreur("Erreur","Nom de fichier vide");return;}
      else 
      {
        string format= dialogueDemandeTexte("Format","Quel est le format de l'image à enregistrer ?\n tapper 1=JPG, 2=BMP, 3=PNG)");
        if(format.compare("")==0 ){dialogueErreur("Erreur","Format de fichier vide");return;}
        else if (format == "1") {format = "jpg";} 
        else if (format == "2") {format = "bmp";}
        else if (format == "3") {format = "png";} 
        else {dialogueErreur("Erreur", "Format de fichier invalide");return;}
        nomF.append("."+format);
        imgB->exportToFile(nomF.c_str(),format.c_str());
      }
    }
  }
  dialogueMessage("Succès","ImageB enregistrée");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_actionImage_selectionn_e_triggered()
{
  // Etape 11 (TO DO)
  int indice = getIndiceImageSelectionnee();
  if (indice== -1){dialogueErreur("Erreur","Aucune image selectionnée");return;}
  else
  {
    PhotoShop::getInstance().supprimeImageParIndice(indice);
    
    videTableImages();
    Iterateur<Image*> it( *(PhotoShop::getInstance().getImages()));
    while(!it.end())
    {
      Image* img=(Image*)it;
      if(dynamic_cast<ImageRGB*>(img)!=NULL)
      {
        ajouteTupleTableImages(img->getId(),"RGB",to_string(img->getDimension().getHauteur())+ 'x'+ to_string(img->getDimension().getLargeur()),img->getNom());
      }
      else
      {
        ajouteTupleTableImages(img->getId(),"NG",to_string(img->getDimension().getHauteur())+ 'x'+ to_string(img->getDimension().getLargeur()),img->getNom());
      }  
      it++;
    } 
  }
  dialogueMessage("Succès","Image supprimée");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_actionImage_par_id_triggered()
{
  // Etape 11 (TO DO)
  int id=dialogueDemandeInt("Image par id","Quel est l'id de l'image à afficher ?");
  if(id<=0){dialogueErreur("Erreur","Id invalide");return;}
  else if(PhotoShop::getInstance().getImageParId(id)==NULL){dialogueErreur("Erreur",("Image avec id("+to_string(id)+") existe pas").c_str());return;}
  else
  {

    PhotoShop::getInstance().supprimeImageParId(id);
    
    videTableImages();
    Iterateur<Image*> it( *(PhotoShop::getInstance().getImages()));
    while(!it.end())
    {
      Image* img=(Image*)it;
      if(dynamic_cast<ImageRGB*>(img)!=NULL)
      {
        ajouteTupleTableImages(img->getId(),"RGB",to_string(img->getDimension().getHauteur())+ 'x'+ to_string(img->getDimension().getLargeur()),img->getNom());
      }
      else
      {
        ajouteTupleTableImages(img->getId(),"NG",to_string(img->getDimension().getHauteur())+ 'x'+ to_string(img->getDimension().getLargeur()),img->getNom());
      }  
      it++;
    } 
    dialogueMessage("Succès","Image supprimée");
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_actionCouleur_TRUE_pour_ImageB_triggered()
{
  // Etape 12 (TO DO)

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_actionCouleur_FALSE_pour_imageB_triggered()
{
  // Etape 12 (TO DO)

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_actionImporterCSV_triggered()
{
  // Etape 13 (TO DO)

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_actionReset_triggered()
{
  // Etape 14 (TO DO)

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions selection sur la table des images ////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_tableWidgetImages_itemSelectionChanged()
{
  // Etape 11 (TO DO)
  int indice = getIndiceImageSelectionnee();
  if (indice== -1){/*dialogueErreur("Erreur","Aucune image selectionnée");*/return;}
  else
  {
    ImageNG* imgNG= dynamic_cast<ImageNG*>(PhotoShop::getInstance().getImageParIndice(indice));
    ImageRGB* imgRGB= dynamic_cast<ImageRGB*>(PhotoShop::getInstance().getImageParIndice(indice));
    //vider
    setImageNG("selection ");
    setParametresImageNG();
    setNomImage("");

    if(imgNG != NULL)
    {
      setNomImage(imgNG->getNom()); 
      setParametresImageNG(imgNG->getMaximun(),imgNG->getMinimum(), imgNG->getLuminance(), imgNG->getContraste());
      setImageNG("selection",imgNG); 
    }
    
    else if(imgRGB !=NULL)
    {
      setNomImage(imgRGB->getNom());
      setImageRGB("selection",imgRGB);  
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions clics sur les boutons ////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_pushButtonModifierNom_clicked()
{
  // Etape 11 (TO DO)
  int indice = getIndiceImageSelectionnee();
  if (indice== -1){dialogueErreur("Erreur","Aucune image selectionnée");return;}
  else
  {
    string tmp= getNomImage();
    
    if(PhotoShop::getInstance().getImageParIndice(indice)->getNom()== tmp){return;}

    PhotoShop::getInstance().getImageParIndice(indice)->setNom(tmp);
    videTableImages();
    Iterateur<Image*> it( *(PhotoShop::getInstance().getImages()));
    while(!it.end())
    {
      Image* img=(Image*)it;
      if(dynamic_cast<ImageRGB*>(img)!=NULL)
      {
        ajouteTupleTableImages(img->getId(),"RGB",to_string(img->getDimension().getHauteur())+ 'x'+ to_string(img->getDimension().getLargeur()),img->getNom());
      }
      else
      {
        ajouteTupleTableImages(img->getId(),"NG",to_string(img->getDimension().getHauteur())+ 'x'+ to_string(img->getDimension().getLargeur()),img->getNom());
      }  
      it++;
    }
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_pushButtonOperande1_clicked()
{
    // Etape 12 (TO DO)

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_pushButtonSupprimeOperande1_clicked()
{
    // Etape 12 (TO DO)

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_pushButtonOperande2_clicked()
{
    // Etape 12 (TO DO)

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_pushButtonSupprimerOperande2_clicked()
{
    // Etape 12 (TO DO)

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_pushButtonResultat_clicked()
{
    // Etape 12 (TO DO)

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_pushButtonSupprimerResultat_clicked()
{
    // Etape 12 (TO DO)

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_pushButtonTraitement_clicked()
{
    // Etape 12 (TO DO)

}
