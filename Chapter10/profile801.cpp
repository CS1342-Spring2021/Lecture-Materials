#include <iostream>
#include <string>

using namespace std;

/**
 * @brief
 * This is used for representing users in LinkedIn
 */
class Profile {
 public:
  // Constructors
  Profile();                     // Default
  Profile(int, string, string);  // Overloaded

  // Setters
  void setFirstName(string);
  void setLastName(string);

  // Getters
  string getFirstName() const;
  string getLastName();

  // Other Functions
  void display() const;

 private:
  int id;
  string firstName;
  string lastName;
};

void Profile::setFirstName(string firstName) { this->firstName = firstName; }

string Profile::getFirstName() const { return firstName; }

void Profile::setLastName(string lastName) { this->lastName = lastName; }

string Profile::getLastName() { return this->lastName; }

Profile::Profile()
    : id{1}, firstName{"No first name"}, lastName{"No last name"} {
  cout << "Default Constructor Called" << endl;
}

Profile::Profile(int initId, string initFirstName, string initLastName)
    : id{initId}, firstName{initFirstName}, lastName{initLastName} {
  cout << "Overloaded Constructor Called" << endl;
  display();
}

void Profile::display() const {
  cout << id << endl;
  cout << firstName << endl;
  cout << lastName << endl;
}

int main() {
  int id = 1;
  string firstName = "Erik";
  string lastName = "Gabrielsen";

  Profile user1 = Profile(id, firstName, lastName);
  Profile user2(2, "George", "Jetson");

  cout << endl;
  user2.display();

  return 0;
}