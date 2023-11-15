#include "pch.h"
#include "CppUnitTest.h"
#include "..\Chapter8-Classes\Ticket.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethodNoArgumentConstructor)
		{
			// AAA convention

			// Arrange - setup the variables we need to test
			int expectedTicketNumber = 0;
			string expectedCustomerName = "";
			int expectedConfirmationCode = 0;

			// Act - call the code we're testing and get values
			Ticket ticket;
			int actualTicketNumber = ticket.getTicketNumber();
			string actualCusomterName = ticket.getCusomterName();
			int actualConfirmationCode = ticket.getConfirmationCode();

			// Asssert  - did we get what we expect
			Assert::AreEqual(expectedTicketNumber, actualTicketNumber);
			Assert::AreEqual(expectedCustomerName, actualCusomterName);
			Assert::AreEqual(expectedConfirmationCode, actualConfirmationCode);

		}

		TEST_METHOD(TestMethodConstructorWithParameters)
		{
			// AAA convention

			// Arrange - setup the variables we need to test
			int expectedTicketNumber = 42;
			string expectedCustomerName = "Eric";
			int expectedConfirmationCode = 123456;

			// Act - call the code we're testing and get values
			Ticket ticket(expectedTicketNumber, expectedCustomerName, expectedConfirmationCode);
			int actualTicketNumber = ticket.getTicketNumber();
			string actualCusomterName = ticket.getCusomterName();
			int actualConfirmationCode = ticket.getConfirmationCode();

			// Asssert  - did we get what we expect
			Assert::AreEqual(expectedTicketNumber, actualTicketNumber);
			Assert::AreEqual(expectedCustomerName, actualCusomterName);
			Assert::AreEqual(expectedConfirmationCode, actualConfirmationCode);

		}

		TEST_METHOD(TestMethodSetTicketNumber)
		{
			// AAA convention

			// Arrange - setup the variables we need to test
			int expectedTicketNumber = 42;
			Ticket ticket;

			// Act - call the code we're testing and get values
			ticket.setTicketNumber(expectedTicketNumber);
			int actualTicketNumber = ticket.getTicketNumber();
			

			// Asssert  - did we get what we expect
			Assert::AreEqual(expectedTicketNumber, actualTicketNumber);
		}

		TEST_METHOD(TestMethodSetTicketNumberNegative)
		{
			// AAA convention

			// Arrange - setup the variables we need to test
			int expectedTicketNumber = 0;
			Ticket ticket;

			// Act - call the code we're testing and get values
			ticket.setTicketNumber(-10);
			int actualTicketNumber = ticket.getTicketNumber();


			// Asssert  - did we get what we expect
			Assert::AreEqual(expectedTicketNumber, actualTicketNumber);
		}
	};
}
