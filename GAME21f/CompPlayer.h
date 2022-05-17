﻿#pragma once
#include <iostream>
#include <random>

using namespace std;

int counter = 36;
int arrayRepeatCards[12] = { 0,0,0,0,0,0,0,0,0,0,0,0 }; // êîë-âî ïîâòîðîâ

//ñ÷åò÷èê êîë-âà êàðò
int card_accounting(int c) {
	if (c > 11) {
		c--;
	}
	else {
		cout << "\n\nОбновление колоды!!!\n\n";
		for (int i = 0; i < 12; i++) {
			arrayRepeatCards[i] = 0;
		}
		c = 36;
	}
	return c;
}
// ðàíäîìíàÿ âûäà÷à êàðò. Íà÷àëî
int random_issuance_of_cards() {
	int random_card;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(2, 11);
	random_card = dist(gen);
	while (random_card == 5) {
		mt19937 gen(rd());

		uniform_int_distribution<> dist(2, 11);
		random_card = dist(gen);
	}
	return random_card;
}

// ó÷åò ïîâòîðÿþùèõñÿ êàðò
int check_cards() {
	int random_card = random_issuance_of_cards();
	counter = card_accounting(counter);
	do {
		if (arrayRepeatCards[random_card] >= 4)
			random_card = random_issuance_of_cards();
		else {
			arrayRepeatCards[random_card]++;
			for (int i = 0; i < 12; i++) {
				cout << arrayRepeatCards[i] << " ";
			}
			cout << endl;
			return random_card;
		}
	} while (true);
}
//ðàíäîìíàÿ âûäà÷à êàðò. Êîíåö


//õîä èãðîêà
int player_turn() {
	return check_cards();
}

//õîä êîìïüþòåðà
int computer_turn() {
	int summa = 0;
	summa += check_cards();
	summa += check_cards();
	srand(time(NULL));
	int a, b, c;
	a = rand() % 2; // 50%
	b = rand() % 4; // 25%
	c = rand() % 10;// 10%
	while (summa <= 21)
	{
		if (summa < 11) summa += check_cards();
		else if (10 < summa && summa < 14) {
			if (b == 3) summa += check_cards();
			else break;
		}
		else if (13 < summa && summa < 16) {
			if (a) summa += check_cards();
			else break;
		}
		else if (15 < summa && summa < 18) {
			if (b == 3) summa += check_cards();
			else break;
		}
		else if (17 < summa && summa < 20) {
			if (c == 9) summa += check_cards();
			else break;
		}
	}
	return summa;
}

//óñëîâèÿ âûéãðûøà
bool win(int summa_user, int summa_comp) {
	cout << "Сумма очков компьютера - " << summa_comp << endl;
	cout << "Ваша итоговая сумма - " << summa_user << endl;
	if (summa_user == 21) cout << "Победа игрока\n";
	else if (summa_user > 21) cout << "Победа компьютера\n";
	else if (summa_comp > 21) cout << "Победа игрока\n";
	else if (summa_user == summa_comp) cout << "Ничья\n";
	else if (summa_user > summa_comp) cout << "Победа игрока\n";
	else if (summa_user < summa_comp) cout << "Победа компьютера\n";
	else if (summa_user == summa_comp) cout << "Ничья\n";

	return false;
}