/* Include Dpendencies */
#include <iostream>
#include <string>
#include <array>

/* Declerations of variables and class*/
bool ProgIsRunning = true;

/* Init values */
int NumberOfPersons = -1;
constexpr int ARR_MAX_SIZE = 100;
constexpr int ID_INIT = 0;
constexpr int AGE_INIT = 0;

/* Enum to save the options in readable way */
enum class option_t
{
	ADD_RECORD = 1,
	FETCH_RECORD = 2,
	QUIT = 3
};
constexpr option_t DEFAULT_OPTION = option_t::ADD_RECORD;
/* Number of options in our program */
constexpr int NUMBERS_OF_OPTIONS = 3;
/* Array to the save the options of the program */
std::array<option_t, NUMBERS_OF_OPTIONS> options{ option_t::ADD_RECORD,option_t::FETCH_RECORD, option_t::QUIT };

/* Class to save the information of the people */
class record
{
	/* Variables of the class */
public:
	std::string name;
	int age{ 0 };

	/* Operation of the class */
	void setRecord(const std::string input_name,const int input_age)
	{
		name = input_name;
		age = input_age;
	}

	void showRecord()
	{
		std::cout << "User Name: " << name << "\n";
		std::cout << "User Age: " << age << "\n\n";
	}
	
};
/* Array to the save the records of persons */
std::array<record, ARR_MAX_SIZE> records;

/* Function Prototypes */
std::istream& operator>> (std::istream& stream, option_t& input);
record FetchRecord(const int ID);
std::string to_string(const option_t option);
void printOptions();
void TakeOption(option_t& currentOption);
void printMsg(const std::string msg);


/* Main Program */
int main(void)
{
	option_t currentOption = DEFAULT_OPTION;
	int ID = ID_INIT;
	std::string nameOfUser;
	int ageOfUser = AGE_INIT;
	
	printMsg("User SignUp Application\n\n");

	while (ProgIsRunning)
	{
	/* Take the option from the user */
	printOptions();
	TakeOption(currentOption);

	switch (currentOption)
	{
		case option_t::ADD_RECORD:
			/* Increasing person record*/
			NumberOfPersons++;
			/* Taking the name of the person */
			printMsg("\nPlease enter user name and age:\nUser Name: ");
			std::cin.ignore();
			std::getline(std::cin, nameOfUser);
			/* Taking the age of the person */
			printMsg("User Age: ");
			std::cin >> ageOfUser;
			/* Setting the information of the person in the records */
			records[NumberOfPersons].setRecord(nameOfUser,ageOfUser);			
			printMsg("\nUser record added successfully\n\n");
		break;

		case option_t::FETCH_RECORD:
			/* Taking the ID to fetch it */
			printMsg("\nPlease enter user ID:\nUser ID: ");
			std::cin >> ID;
			/* Show the record corresponding to the received ID */
			FetchRecord(ID).showRecord();
		break;

		case option_t::QUIT:
			/* Exit the program */
			ProgIsRunning = false;
		break;
		default:
			/* Error message for wrong option selected */
			printMsg("\nEnter Valid option...\n\n");
		break;
	}
}
	return 0;
}

/* Function to return the record correspond to the ID */
record FetchRecord(const int ID)
{
	return records[ID];
}

/* Function to overload to_string function to convert the option selected to corresponding string */
std::string to_string(const option_t option)
{
	std::string optionReturned = "";
	switch (option)
	{
	case option_t::ADD_RECORD:
		optionReturned = "1. Add Record\n";
		break;
	case option_t::FETCH_RECORD:
		optionReturned = "2. Fetch Record\n";
		break;
	case option_t::QUIT:
		optionReturned = "3. Quit\n";
		break;
	default:
		break;
	}
	return optionReturned;
}

/* Function to show the options of the application */
void printOptions()
{
	std::cout << "Please select an option:\n";
	for (option_t option : options)
	{
		std::cout << to_string(option);
	}
}

/* Function to take the option from the user */
void TakeOption(option_t& currentOption)
{
	std::cout << "\nEnter option: ";
	std::cin >> currentOption;
}

/* Function to print a message */
void printMsg(const std::string msg)
{
	std::cout << msg;
}

/* Function to overload cin stream with option type */
std::istream& operator>> (std::istream& stream, option_t& input)
{
	int option_integer;
	stream >> option_integer;

	input = static_cast<option_t>(option_integer);

	return stream;
}