// variant #11
#include <iostream>
#include <cstring>

using namespace std;

struct Date
{
  int d;
  int m;
  int y;
};

struct Record // #1
{
  char sport[25];
  char discipline[50];
  char type[50];
  bool gender; // 0 - female
  Date date;   // 00 00 0000
  char country[50];
  char achievement[50];
};

struct RecordsSize
{
  Record *records;
  int size;
};

RecordsSize getRecords();
void printRecords(RecordsSize);
int countRecords(RecordsSize, string);
RecordsSize femWorldRecords(RecordsSize, int);

int main()
{
  // #2а
  RecordsSize rs;    // #2б
  rs = getRecords(); // #2в
  printRecords(rs);  // #2г

  char sport[25];
  printf("Count by sports. Enter the sport's name: ");
  scanf("%s", sport);
  int spCount = countRecords(rs, sport); // #7.1
  printf("Quantity: %d \n", spCount);

  RecordsSize femRecords = femWorldRecords(rs, 2023);
  printf("2023 female world records: \n");
  printRecords(femRecords); // #7.2

  free(femRecords.records);
  free(rs.records);
  return 0;
}

RecordsSize getRecords()
{
  FILE *file = fopen("records.txt", "r");
  int count;
  fscanf(file, "%d\n", &count);
  Record *records = (Record *)calloc(count, sizeof(Record));
  for (int i = 0; i < count; i++)
  {
    int gender;
    fscanf(file, "%s %s %s %d %d.%d.%d %s %s\n",
           records[i].sport,
           records[i].discipline,
           records[i].type,
           &gender,
           &records[i].date.d, &records[i].date.m, &records[i].date.y,
           records[i].country,
           records[i].achievement);
    records[i].gender = gender == 0;
  }
  fclose(file);
  RecordsSize result = {records, count};
  return result;
}

void printRecords(RecordsSize rs)
{
  for (int i = 0; i < rs.size; i++)
  {
    printf("%s %s %s %s %d.%d.%d %s %s\n",
           rs.records[i].sport,
           rs.records[i].discipline,
           rs.records[i].type,
           rs.records[i].gender == 0 ? "Female" : "Male",
           rs.records[i].date.d, rs.records[i].date.m, rs.records[i].date.y,
           rs.records[i].country,
           rs.records[i].achievement);
  }
}

int countRecords(RecordsSize rs, string sport)
{
  int total = 0;
  for (int i = 0; i < rs.size; i++)
  {
    if (rs.records[i].sport == sport)
      total++;
  }
  return total;
}

RecordsSize femWorldRecords(RecordsSize rs, int year)
{
  int count = 0;
  Record *records = (Record *)calloc(count, sizeof(Record));
  for (int i = 0; i < rs.size; i++)
  {
    if (strcmp(rs.records[i].type, "world") == 0 && rs.records[i].date.y == year && !rs.records[i].gender)
    {
      count++;
      records = (Record *)realloc(records, count * sizeof(Record));
      records[count - 1] = rs.records[i];
    }
  }
  RecordsSize newRs = {records, count};
  return newRs;
}