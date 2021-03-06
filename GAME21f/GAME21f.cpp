using namespace std;
// game 21
void main_menu();
void step_game(int cards_first, int cards_next);
void cards_show(int card);

char flag = 'y';

int main()
{
	setlocale(LC_ALL, "");
	while (::flag == 'y') {
		system("cls");
		main_menu();
		if (::flag == 'n') break;
		cout << "Продолжить игру? (y/n)\n";
		cin >> ::flag;
	}
}

// интерфейс игры. Начало
void main_menu() {
	cout << "Добро пожаловать в игру 21!\n";
	cout << "Хотите начать? (y/n)\n";
	string flag;
	cin >> flag;
	if (flag == "y") {
		int first_card = check_cards(), second_card = check_cards();
		step_game(first_card, second_card);
	}
	else {
		cout << "До свидания!\n";
		::flag = 'n';
	}
}

// Вывод самих карт
void cards_show(int card) {
	string six = "********\n"
		"* 6    *\n"
		"*      *\n"
		"*      *\n"
		"*      *\n"
		"*    9 *\n"
		"********\n";
	string seven = "********\n"
		"* 7    *\n"
		"*      *\n"
		"*      *\n"
		"*      *\n"
		"*    7 *\n"
		"********\n";
	string eight = "********\n"
		"* 8    *\n"
		"*      *\n"
		"*      *\n"
		"*      *\n"
		"*    8 *\n"
		"********\n";
	string nine = "********\n"
		"* 9    *\n"
		"*      *\n"
		"*      *\n"
		"*      *\n"
		"*    6 *\n"
		"********\n";
	string ten = "********\n"
		"* 10   *\n"
		"*      *\n"
		"*      *\n"
		"*      *\n"
		"*   10 *\n"
		"********\n";
	string valet = "********\n"
		"*  *** *\n"
		"*   ** *\n"
		"* **** *\n"
		"*  *** *\n"
		"*valet *\n"
		"********\n";
	string queen = "********\n"
		"* **** *\n"
		"*  *** *\n"
		"* **** *\n"
		"*  *** *\n"
		"*queen *\n"
		"********\n";
	string king = "********\n"
		"* ** * *\n"
		"*   ** *\n"
		"* **** *\n"
		"*  *** *\n"
		"* king *\n"
		"********\n";
	string tuz = "********\n"
		"* **** *\n"
		"*      *\n"
		"*   *  *\n"
		"*      *\n"
		"* **** *\n"
		"********\n";
	switch (card) {
	case(2):
		cout << valet;
		break;
	case(3):
		cout << queen;
		break;
	case(4):
		cout << king;
		break;
	case(6):
		cout << six;
		break;
	case(7):
		cout << seven;
		break;
	case(8):
		cout << eight;
		break;
	case(9):
		cout << nine;
		break;
	case(10):
		cout << ten;
		break;
	case(11):
		cout << tuz;
		break;
	default:
		break;

	}

}
void step_game(int cards_first, int cards_next) {
	string flag;
	int extra_card; // дополнительная карта
	bool f = true;
	int summa_user = cards_first + cards_next, summa_comp = 0;
	cout << "Ваши карты: " << cards_first << "," << cards_next << endl;
	cards_show(cards_first);
	cards_show(cards_next);
	cout << "Итоговая сумма: " << cards_first + cards_next << endl;
	while (f) {
		cout << "Хотите взять еще одну карту?(y/n)\n";
		cin >> flag;
		if (flag == "y") {
			extra_card = player_turn();
			summa_user += extra_card;
			cout << "Ваша карта: " << extra_card << endl;
			cards_show(extra_card);
			cout << "Итоговая сумма: " << summa_user << endl;
			if (summa_user > 21) {
				summa_comp += computer_turn();
				f = win(summa_user, summa_comp);
				continue;
			}
			else if (summa_user == 21) {
				summa_comp += computer_turn();
				f = win(summa_user, summa_comp);
				continue;
			}
		}
		else if (flag == "n") {
			summa_comp += computer_turn();
			f = win(summa_user, summa_comp);
			continue;
		}
		else
		{
			cout << "Неверный ввод, повторите!";
		}
	}
}
// интерфейс игры. Конец
