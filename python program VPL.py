class Account:
    def __init__(self, account_holder, balance=0):
        self.account_holder = account_holder
        self.balance = balance

    def deposit(self, amount):
        self.balance += amount
        print(f"Deposited ${amount}. Current balance: ${self.balance}")

    def withdraw(self, amount):
        if amount > self.balance:
            print("Insufficient funds")
        else:
            self.balance -= amount
            print(f"Withdrew ${amount}. Current balance: ${self.balance}")


class SavingsAccount(Account):
    def __init__(self, account_holder, balance=0, interest_rate=0.02, atm_facility=True, min_balance=100):
        super().__init__(account_holder, balance)
        self.interest_rate = interest_rate
        self.atm_facility = atm_facility
        self.min_balance = min_balance

    def calculate_interest(self):
        interest = self.balance * self.interest_rate
        self.deposit(interest)
        print(f"Interest earned: ${interest}")


class PremiumSavingsAccount(SavingsAccount):
    def __init__(self, account_holder, balance=0, interest_rate=0.03, atm_facility=True, min_balance=500,
                 insurance_amount=1000, atm_limit=1000, credit_card_balance=0):
        super().__init__(account_holder, balance, interest_rate, atm_facility, min_balance)
        self.insurance_amount = insurance_amount
        self.atm_limit = atm_limit
        self.credit_card_balance = credit_card_balance

    def get_credit_card_balance(self):
        print(f"Credit Card Balance: ${self.credit_card_balance}")


class LoanAccount(Account):
    def __init__(self, account_holder, balance=0, loan_amount=0, interest_rate=0.05, loan_term=12, fees_and_charges=0):
        super().__init__(account_holder, balance)
        self.loan_amount = loan_amount
        self.interest_rate = interest_rate
        self.loan_term = loan_term
        self.fees_and_charges = fees_and_charges

    def calculate_loan_repayment(self):
        total_repayment = self.loan_amount * (1 + self.interest_rate) + self.fees_and_charges
        self.deposit(total_repayment)
        print(f"Loan Repayment: ${total_repayment}")


class CurrentAccount(Account):
    def __init__(self, account_holder, balance=0, min_balance=1000, internet_banking=True, penalty=20):
        super().__init__(account_holder, balance)
        self.min_balance = min_balance
        self.internet_banking = internet_banking
        self.penalty = penalty

    def check_minimum_balance(self):
        if self.balance < self.min_balance:
            print(f"Account balance is below minimum. Penalty of ${self.penalty} applied.")
            self.balance -= self.penalty


# Example Usage:
savings_account = SavingsAccount("John Doe", 500)
savings_account.deposit(1000)
savings_account.calculate_interest()

premium_savings_account = PremiumSavingsAccount("Jane Doe", 1000)
premium_savings_account.deposit(2000)
premium_savings_account.get_credit_card_balance()

loan_account = LoanAccount("Bob", loan_amount=5000)
loan_account.calculate_loan_repayment()

current_account = CurrentAccount("Alice", 800)
current_account.check_minimum_balance()
current_account.withdraw(700)
current_account.check_minimum_balance()
