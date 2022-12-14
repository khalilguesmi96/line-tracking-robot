const int capteurGauche = 7;
const int capteurCentre = 4;
const int capteurDroit = 3;
bool etatCapteurGauche;
bool etatCapteurCentre;
bool etatCapteurDroit;
const int moteurGaucheA = 5;
const int moteurGaucheR = 6;
const int moteurDroitA = 11;
const int moteurDroitR = 10;

char valSerie;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(capteurGauche, INPUT);
  pinMode(capteurCentre, INPUT);
  pinMode(capteurDroit, INPUT);
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(moteurGaucheA, OUTPUT);
  pinMode(moteurGaucheR, OUTPUT);
  pinMode(moteurDroitA, OUTPUT);
  pinMode(moteurDroitR, OUTPUT);
}
void avancer()
{
  digitalWrite(moteurGaucheA, HIGH);
  digitalWrite(moteurGaucheR, LOW);
  digitalWrite(moteurDroitA, HIGH);
  digitalWrite(moteurDroitR, LOW);
}

void gauche()
{
  digitalWrite(moteurGaucheA, LOW);
  digitalWrite(moteurGaucheR, LOW);
  digitalWrite(moteurDroitA, HIGH);
  digitalWrite(moteurDroitR, LOW);
}
void droite()
{
  digitalWrite(moteurGaucheA, HIGH);
  digitalWrite(moteurGaucheR, LOW);
  digitalWrite(moteurDroitA, LOW);
  digitalWrite(moteurDroitR, LOW);
}
void reculer()
{
  digitalWrite(moteurGaucheA, LOW);
  digitalWrite(moteurGaucheR, HIGH);
  digitalWrite(moteurDroitA, LOW);
  digitalWrite(moteurDroitR, HIGH);
}
void arreter()
{
  digitalWrite(moteurGaucheA, LOW);
  digitalWrite(moteurGaucheR, LOW);
  digitalWrite(moteurDroitA, LOW);
  digitalWrite(moteurDroitR, LOW);
}
void pivoterGauche()
{
  digitalWrite(moteurGaucheA, LOW);
  digitalWrite(moteurGaucheR, HIGH);
  digitalWrite(moteurDroitA, HIGH);
  digitalWrite(moteurDroitR, LOW);
}
void pivoterDroite()
{
  digitalWrite(moteurGaucheA, HIGH);
  digitalWrite(moteurGaucheR, LOW);
  digitalWrite(moteurDroitA, LOW);
  digitalWrite(moteurDroitR, HIGH);
}

void loop()
{
  // put your main code here, to run repeatedly:
  etatCapteurGauche = digitalRead(capteurGauche);
  etatCapteurCentre = digitalRead(capteurCentre);
  etatCapteurDroit = digitalRead(capteurDroit);

  if(etatCapteurCentre) //Si le capteur du centre d??tecte du noir
  {
    if ((etatCapteurGauche) && (!etatCapteurDroit)) //S'il y a du noir ?? gauche et du blanc ?? droite, tourner ?? gauche
    {
      gauche();
    }
    else if ((!etatCapteurGauche) && (etatCapteurDroit)) //S'il y a du blanc ?? gauche et du noir ?? droite, tourner ?? droite
    {
     droite();
    }
    else //Si les conditions plus haut ne s'appliquent pas, continuer tout droit
    {
      avancer();
    }
  }
  else //Si le capteur du centre d??tecte du blanc
  {
    if ((etatCapteurGauche) && (!etatCapteurDroit)) //S'il y a du noir ?? gauche et du blanc ?? droite, tourner ?? gauche
    {
      Serial.println("Tourner ?? gauche");
    }
    else if ((!etatCapteurGauche) && (etatCapteurDroit)) //S'il y a du blanc ?? gauche et du noir ?? droite, tourner ?? droite
    {
      Serial.println("Tourner ?? droite");
    }
    else //Si les conditions plus haut ne s'appliquent pas, reculer
    {
      Serial.println("Reculer");
    }
  }
}
