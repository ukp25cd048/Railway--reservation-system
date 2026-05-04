# Railway Reservation System

# Total seats
TOTAL_SEATS = 50
available_seats = list(range(1, TOTAL_SEATS + 1))

# Store bookings
bookings = {}

# Generate booking ID
def generate_booking_id():
    return len(bookings) + 1


# Check Availability
def check_availability():
    print(f"\nAvailable Seats: {len(available_seats)}")
    print("Seat Numbers:", available_seats)


# Book Ticket
def book_ticket():
    if len(available_seats) == 0:
        print("\nNo seats available!")
        return

    name = input("Enter Name: ")
    age = int(input("Enter Age: "))

    seat = available_seats.pop(0)
    booking_id = generate_booking_id()

    bookings[booking_id] = {
        "name": name,
        "age": age,
        "seat": seat
    }

    print(f"\nBooking Successful!")
    print(f"Booking ID: {booking_id}")
    print(f"Seat Number: {seat}")


# View Ticket
def view_ticket():
    booking_id = int(input("Enter Booking ID: "))

    if booking_id in bookings:
        data = bookings[booking_id]
        print("\n--- Ticket Details ---")
        print(f"Name: {data['name']}")
        print(f"Age: {data['age']}")
        print(f"Seat: {data['seat']}")
    else:
        print("Invalid Booking ID!")


# Cancel Ticket
def cancel_ticket():
    booking_id = int(input("Enter Booking ID to cancel: "))

    if booking_id in bookings:
        seat = bookings[booking_id]['seat']
        available_seats.append(seat)
        available_seats.sort()

        del bookings[booking_id]

        print("Booking Cancelled Successfully!")
    else:
        print("Invalid Booking ID!")


# Main Menu
def menu():
    while True:
        print("\n===== Railway Reservation System =====")
        print("1. Check Availability")
        print("2. Book Ticket")
        print("3. View Ticket")
        print("4. Cancel Ticket")
        print("5. Exit")

        choice = input("Enter your choice: ")

        if choice == '1':
            check_availability()
        elif choice == '2':
            book_ticket()
        elif choice == '3':
            view_ticket()
        elif choice == '4':
            cancel_ticket()
        elif choice == '5':
            print("Thank you!")
            break
        else:
            print("Invalid choice!")


# Run program
menu()
