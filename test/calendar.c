#include <stdio.h>
#include <stdbool.h>

// Funktionsprototypen
void printCalendar(int month, int year);
void printMonthTitle(int month, int year);
void printMonthName(int month);
void printMonthBody(int month, int year);
int getStartDay(int month, int year);
int getTotalNumberOfDays(int month, int year);
int getNumberOfDaysInMonth(int month, int year);
bool isLeapYear(int year);

int main() {
	int year, month;

	printf("Bitte geben sie eine Jahreszahl an (z.B. 2001): ");
	scanf("%d", &year);
	printf("Bitte geben sie eine Zahl für den Monat zwischen 1 und 12 an:");
	scanf("%d", &month);

	printCalendar(month, year);

	return 0;
}

// Funktionsimplementierungen

void printCalendar(int month, int year) {
	printMonthTitle(month, year);
	printMonthBody(month, year);
}

void printMonthTitle(int month, int year) {
	printMonthName(month);

	printf(" %d        \n", year);
	printf(")----------------------------------------------------\n");
	printf("Sun\tMon\tTue\tWed\tThu\tFri\tSat\n");
}

void printMonthName(int month) {
	switch (month) {
		case 1:
			printf("\t\tJanuar");
			break;
        case 2:
            printf("\t\tFabruar");
            break;
        case 3:
            printf("\t\tMärz");
            break;
        case 4:
            printf("\t\tApril");
            break;
        case 5:
            printf("\t\tMai");
            break;
        case 6:
            printf("\t\tJuni");
            break;
        case 7:
            printf("\t\tJuli");
            break;
        case 8:
            printf("\t\tAugust");
            break;
        case 9:
            printf("\t\tSeptember");
            break;
        case 10:
            printf("\t\tOktober");
            break;
        case 11:
            printf("\t\tNovember");
            break;
        case 12:
            printf("\t\tDezember");
            break;
        default:
            printf("Falsche Eingabe - Keinpassender Monat gefunden!");
            break;
    }
}

void printMonthBody(int month, int year) {
	int startDay = getStartDay(month, year);
	int numberOfDaysInMonth = getNumberOfDaysInMonth(month, year);

	for (int i = 0; i < startDay; i++) {
		printf("\t");
	}

	for (int i = 1; i <= numberOfDaysInMonth; i++) {
		printf("%d\t", i);

		if ((i + startDay) % 7 == 0) {
			printf("\n");
		}
	}

	printf("\n");
}

int getStartDay(int month, int year) {
	int startDay1800 = 3;

	int totalNumberOfDays = getTotalNumberOfDays(month, year);

	return (totalNumberOfDays + startDay1800) % 7;
}

int getTotalNumberOfDays(int month, int year) {
	int total = 0;

	for (int i = 1800; i < year; i++) total += isLeapYear(i) ? 366 : 365;

	for (int i = 1; i < month; i++) {
		total += getNumberOfDaysInMonth(i, year);
	}

	return total;
}

int getNumberOfDaysInMonth(int month, int year) {
	if (month >= 1 && month <= 12) return 31;
	else if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
	else if (month == 2) return isLeapYear(year) ? 29 : 28;

	return 0;
}

bool isLeapYear(int year) {
	return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}
