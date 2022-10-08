/*Да се дефинира клас Bank_acc, съхраняващ информация за банкови клиенти:
име, адрес, номер на сметка, сума. Името и адреса да се реализират динамично,
а номер на сметка и сумата да не са указатели. Класът да има 2 конструктора 
(един от които подразбиращ се, който въвежда член – данните от клавиатурата),
деструктор, който съобщава за унищожаване на обект и освобождава памет и методи
за извеждане на информация по въведен номер на сметка, теглене и внасяне на пари.
Член-данните на класа да са с частен достъп (private). В главната функция да се 
дефинира и обработва масив Klients от клиенти.
Главната функция да не е приятелска за класа.*/

#include <iostream>
#include <string>

using namespace std;

class Bank_acc {
	string* name; /// tekstov ukazatel kym promenliva za ime
	string* address; /// tekstov ukazatel kym promenliva za adres
	int accNumber; /// celochislena promenliva za klientski nomer
	float sum; ///promenliva ot realen tip za suma v smetka
	static int numOfClients; ///statichna celochislena promenliva za broi bankovi akaunti
public:
	Bank_acc(); ////deklaraciq na konstruktor po podrazbirane
	Bank_acc(string name, string address, int accnumber, float suma); ////deklaraciq na konstruktor s podavane na parametri
	~Bank_acc(); /// deklaraciq na destruktor


	static void setNumClients(int br)    ////// Setter na statichnata promeliva - da podade stoinost kym numOfClients
	{
		numOfClients = br;
	}
	int getNumClients() ///// Getter
	{
		return numOfClients;
	}


	void OtvoriAkaunt() //// Chlen metod za syzdavane na bankov akaunt
	{
		name = new string; ///Zadelena dinamichna pamet za promenlivata name
		address = new string;///Zadelena dinamichna pamet za promenlivata address
		
		cout << "\n";
		cout << "Vyvedi ime na klient : ";
		getline(cin>>ws , (*name)); ////vyvejdame samata stoinost na dinamichnata promenliva , a ne neiniqt adres
		cout << "\n";

		

		cout << "\n";
		cout << "Vyvedi adres na klient : ";
		getline(cin>>ws , (*address));////vyvejdame samata stoinost na dinamichnata promenliva , a ne neiniqt adres
		cout << "\n";
		

		cout << "Vyvedi klientski nomer na klienta : ";
		cin >> accNumber;
		cout << endl;

		cout << "Vyvedi suma na klienta : ";
		cin >> sum;
		cout << endl;


	}
	void PokajiAkaunt()
	{
		cout << "Ime : " << (*name) << endl;
		cout << "Adres : " << (*address) << endl;
		cout << "Klientski nomer : " << accNumber << endl;
		cout << "Suma v smetkata : " << sum << endl;
	}
	void Vnesi()
	{
		float sumVnasqne; ///Deklarirame realna promenliva , koqto se pribavq kym sumata v smetkata
		cout << "Napishete suma , koqto iskate da vnesete ot smetkata : ";
		cin >> sumVnasqne;
		sum = sum + sumVnasqne;

	}
	void Iztegli()
	{
		float sumIzteglqne;/// Deklarirame realna promenliva , koqto se izvajda kym sumata v smetkata
		cout << "Napishete suma , koqto iskate da izteglite ot smetkata : ";
		cin >> sumIzteglqne;
		if (sumIzteglqne <= sum)/////Ako sumata,koqto teglim e po-malka ili ravna na sumata v smetkata, togava se izpylnqva ...
			sum = sum - sumIzteglqne;
		else 
			cout << "Nedostatychen balans ..." << endl;////Ako sumata , koqto teglim e po-golqma ot balansa v smetkata

	}
	int TyrseneNomer(int UserInput1) ////funkciq,koqto tyrsi dali ima vyveden klientski nomer
	{
		if (UserInput1 == accNumber)////Ako ima takyv klientski nomer , kato tozi , koito e vyveden za UserInput1 , to izpylnqva
		{
			PokajiAkaunt();
			return(1);////Vryshta 1ca kato rezultat samata funkciq pri tozi sluchai
		}
		return (0);/////////Ako nqma takyv klientski nomer pri proverka , funkciqta vryshta 0 kato rezultat
	}
};

Bank_acc::Bank_acc()////Definiciq na konstruktor po podrazbirane
{
	OtvoriAkaunt();/////Syzdava bankov akaunt
}

Bank_acc::Bank_acc(string name1, string address1, int accnumber, float suma)///Definiciq na konstruktor s podavane na parametri
{
	cout << "Detaili na smetka" << endl;
	cout << "Ime : " << name1 << endl;
	cout << "Adres : " << address1 << endl;
	cout << "Klientski nomer : " << accnumber << endl;
	cout << "Suma v smetkata : " << suma << endl;
}
Bank_acc::~Bank_acc() ///////Definiciq na destruktor
{
	cout << "Osvobojdavane na pamet !" << endl;
	
}

int Bank_acc::numOfClients; ///// Chast ot definiciqta na chastnata statichna promenliva

int main() ////Glavna funkciq
{
	int brKlienti; ////Promenliva ,koqto vyvejdame za broq klienti
	do {
		cout << "Vyvedete broq na klienti : ";
		cin >> brKlienti;
	} while ((brKlienti < 1)||(brKlienti > 1000));

	Bank_acc::setNumClients(brKlienti);//////kazvame chastnata promenliva numOfClients=brKlienti za broq na klientskite akaunti,koito shte se syzdadyt

	Bank_acc* Klients = new Bank_acc[brKlienti];/////Syzdavame dinamichen masiv ot obekti ot klas Bank_acc s razmernost [brKlienti]

	int found = 0;////// promenliva , koqto shte izpolzvame za tyrsene
	int Izbor = 0; ///// izbor na terminala
	int UserInput2 = 0; //////Vyvedeniqt tekst pri izbora na opciq ot terminala

	cout << endl;

	do {
		cout << endl;
		cout << "Izberete opciq ..." << endl;
		cout << endl;
		cout << "1.Izvikvane na akaunti " << endl;
		cout << "2.Tyrsene na akaunt po klientski nomer " << endl;
		cout << "3.Depozirane " << endl;
		cout << "4.Izteglqne" << endl;
		cout << "5.Exit" << endl;
		cout << endl;
		cout << "Vyvedete izbora si tuk :";
		cin >> Izbor;
		cout << endl;

		switch (Izbor) {
		case 1:
			for (int i =0; i <= brKlienti - 1; i++) ////Poneje stava vypros za masiv , pravim operacii s cikyl for
			{
				Klients[i].PokajiAkaunt();///Za vsqko zavyrtane na cikyla izpylni funkciqta PokajiAkaunt()
			}
			break;
		case 2:
			cout << "Vyvedete klientski nomer za proverka :  ";
			cin >> UserInput2;////UserInput2 e klientskiqt nomer za proverka , koito shte se proveri dali ima takyv sred akauntite
			for (int i = 0; i <= brKlienti - 1; i++)///Poneje stava vypros za masiv , pravim operacii s cikyl for
			{
				found = Klients[i].TyrseneNomer(UserInput2);////Na found se prisvuqva funkciqta : Klients[i].TyrseneNomer(UserInput2)
				if (found) ////(found!=0) Proverqva dali ima found e razlichno ot 0 i ako e , izpylqva break i izliza ot sluchaq
					break;
			}
			if (!found)//// (found==0) Ako found e ravno na 0 , izpylnqva syobshtenieto otdolu
			{
				cout << "Nqma akaunt s takyv klientski nomer" << endl;
			}
			break;

		case 3:
			cout << "Vyvedete klientski nomer ,v chiqto smetka iskate da vnesete pari : ";
			cin >> UserInput2;/////UserInput2 e klientskiqt nomer za proverka , koito shte se proveri dali ima takyv sred akauntite
			for (int i = 0; i <= brKlienti - 1; i++)///Poneje stava vypros za masiv , pravim operacii s cikyl for
			{
				found = Klients[i].TyrseneNomer(UserInput2); /////Na found se prisvuqva funkciqta : Klients[i].TyrseneNomer(UserInput2)
				if (found)////// Proverqva dali ima found e razlichno ot 0 i ako e , izpylqva break i izliza ot sluchaq
				{
					Klients[i].Vnesi(); ///// Prilagame funkciqta za vnasqne
					break;///Izliza ot sluchaq
				}
			}
			if (!found)////Ako found==0 
				cout << "Akauntyt ne beshe nameren!!!" << endl;
			break;
		case 4:
			cout << "Vyvedete klientski nomer ,ot chiqto smetka iskate da izteglite pari : ";
			cin >> UserInput2;/////UserInput2 e klientskiqt nomer za proverka , koito shte se proveri dali ima takyv sred akauntite
			for (int i = 0; i <= brKlienti - 1; i++)///Poneje stava vypros za masiv , pravim operacii s cikyl for
			{
				found = Klients[i].TyrseneNomer(UserInput2);/////Na found se prisvuqva funkciqta : Klients[i].TyrseneNomer(UserInput2)
				if (found) /// Proverqva dali ima found e razlichno ot 0 i ako e , izpylqva break i izliza ot sluchaq
				{
					Klients[i].Iztegli();/// Prilagame funkciqta za teglene
					break;
				}
			}
			if (!found)///Ako found==0 
				cout << "Akauntyt ne beshe nameren!!!" << endl;
			break;
		case 5:
			cout << "Priqten den !" << endl;
			break;
		default:
			cout << "Greshna opciq ..." << endl; /////Ako izberesh neshto osven 1,2,3,4,5 kato opciq izpisva tova
		}
	} while (Izbor != 5);////////Da izpylnqva koda dokato izbor e razlichen ot 5 , kogato e = na 5 , izliza ot cikyla

	delete[] Klients;//////Iztrivame dinamichen masiv ot obekti i izvikvame destruktora po tozi nachin

	cout << endl;
	cout << "CHASTNA SMETKA IZVYN SISTEMATA (KONSTRUKTOR2)!!!" << endl;
	cout << endl;
	Bank_acc chastnaSmetka("Stanchev", "TamNqkyde", 15, 20000);/////////Konstruktor No.2

	return 0;////Vryshta 0 kato rezultat glavnata funkciq

	system("pause");/////Ostava v rejim na pauza.
}
