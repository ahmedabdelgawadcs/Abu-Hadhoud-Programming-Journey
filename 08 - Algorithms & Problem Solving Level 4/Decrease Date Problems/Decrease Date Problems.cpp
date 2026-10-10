#include <iostream>
#include <limits>

using namespace std;

struct stDate {
	short day, month;
	int year;
};

int read_positive(string message = "") {
	int number;

	cout << message;
	cin >> number;

	while (number < 1 || cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Should be a Positive Number!" << endl;

		cin >> number;
	}

	return number;
}

short read_day(string message = "") {
	short day = read_positive(message);

	while (day > 31) {
		cout << "Invalid Day!" << endl;
		day = read_positive();
	}

	return day;
}

short read_month(string message = "") {
	short month = read_positive(message);

	while (month > 12) {
		cout << "Invalid Month!" << endl;
		month = read_positive();
	}

	return month;
}

stDate read_date() {
	stDate date;

	date.day = read_day("Please enter a Day? ");
	date.month = read_month("Please enter a Month? ");
	date.year = read_positive("Please enter a Year? ");

	return date;
}

bool is_leap(int year) {
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

short get_month_days(short month, int year) {
	return month == 2 ? is_leap(year) ? 29 : 28 : month <= 7 && month % 2 == 1 || month > 7 && month % 2 == 0 ? 31 : 30;
}

void decrease_date_by_1day(stDate& date) {
	date.day--;

	if (date.day == 0) {
		date.month--;

		if (date.month == 0) {
			date.year--;
			date.month = 12;
		}

		date.day = get_month_days(date.month, date.year);
	}
}

void decrease_date_by_x_days(stDate& date, int days) {
	for (int i = 1; i <= days; i++)
		decrease_date_by_1day(date);
}

void decrease_date_by_1week(stDate& date) {
	decrease_date_by_x_days(date, 7);
}

void decrease_date_by_x_weeks(stDate& date, int weeks) {
	for (int i = 1; i <= weeks; i++)
		decrease_date_by_1week(date);
}

void decrease_date_by_1month(stDate& date) {
	date.month--;

	if (date.month == 0) {
		date.year--;
		date.month = 12;
	}

	short month_days = get_month_days(date.month, date.year);

	if (date.day > month_days)
		date.day = month_days;
}

void decrease_date_by_x_months(stDate& date, int months) {
	for (int i = 1; i <= months; i++)
		decrease_date_by_1month(date);
}

void decrease_date_by_1year(stDate& date) {
	date.year--;

	if (date.day == 29 && date.month == 2 && !is_leap(date.year))
		date.day = 28;
}

void decrease_date_by_x_years(stDate& date, int years) {
	for (int i = 1; i <= years; i++)
		decrease_date_by_1year(date);
}

void decrease_date_by_x_years_faster(stDate& date, int years) {
	date.year -= years;

	if (date.day == 29 && date.month == 2 && !is_leap(date.year))
		date.day = 28;
}

void decrease_date_by_1decade(stDate& date) {
	for (int i = 1; i <= 10; i++)
		decrease_date_by_1year(date);
}

void decrease_date_by_x_decades(stDate& date, int decades) {
	for (int i = 1; i <= decades; i++)
		decrease_date_by_1decade(date);
}

void decrease_date_by_x_decades_faster(stDate& date, int decades) {
	date.year -= decades * 10;

	if (date.day == 29 && date.month == 2 && !is_leap(date.year))
		date.day = 28;
}

void decrease_date_by_1century(stDate& date) {
	decrease_date_by_x_years_faster(date, 100);
}

void decrease_date_by_1millennium(stDate& date) {
	decrease_date_by_x_years_faster(date, 1000);
}

void print_date(stDate date) {
	printf("%d/%d/%d\n", date.day, date.month, date.year);
}

void main() {
	stDate date = read_date();

	cout << '\n';

	cout << "\nDate After\n" << endl;

	decrease_date_by_1day(date);
	cout << "01-Subtracting one day is: ";
	print_date(date);

	decrease_date_by_x_days(date, 10);
	cout << "02-Subtracting 10 days is: ";
	print_date(date);

	decrease_date_by_1week(date);
	cout << "03-Subtracting one week is: ";
	print_date(date);

	decrease_date_by_x_weeks(date, 10);
	cout << "04-Subtracting 10 weeks is: ";
	print_date(date);

	decrease_date_by_1month(date);
	cout << "05-Subtracting one month is: ";
	print_date(date);

	decrease_date_by_x_months(date, 5);
	cout << "06-Subtracting 5 months is: ";
	print_date(date);

	decrease_date_by_1year(date);
	cout << "07-Subtracting one year is: ";
	print_date(date);

	decrease_date_by_x_years(date, 10);
	cout << "08-Subtracting 10 Years is: ";
	print_date(date);

	decrease_date_by_x_years_faster(date, 10);
	cout << "09-Subtracting 10 Years (faster) is: ";
	print_date(date);
	
	decrease_date_by_1decade(date);
	cout << "10-Subtracting one Decade is: ";
	print_date(date);

	decrease_date_by_x_decades(date, 10);
	cout << "11-Subtracting 10 Decades is: ";
	print_date(date);

	decrease_date_by_x_decades_faster(date, 10);
	cout << "12-Subtracting 10 Decade (faster) is: ";
	print_date(date);

	decrease_date_by_1century(date);
	cout << "13-Subtracting One Century is: ";
	print_date(date);

	decrease_date_by_1millennium(date);
	cout << "14-Subtracting One Millennium is: ";
	print_date(date);

	system("pause > 0");
}