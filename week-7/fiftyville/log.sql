SELECT *
FROM crime_scene_reports
WHERE year = 2025
AND month = 7
AND day = 28
AND street = 'Humphrey Street';

SELECT people.*, courthouse_security_logs.*
FROM people
JOIN courthouse_security_logs ON people.license_plate = courthouse_security_logs.license_plate
WHERE courthouse_security_logs.year = 2025
AND courthouse_security_logs.month = 7
AND courthouse_security_logs.day = 28
AND courthouse_security_logs.activity = 'exit'
ORDER BY courthouse_security_logs.minute;

SELECT people.name, interviews.transcript
FROM people
JOIN interviews ON people.id = interviews.person_id
WHERE interviews.year = 2025
AND interviews.month = 7
AND interviews.day = 28;

SELECT people.id, people.name, people.phone_number
FROM people
WHERE name = 'Bruce';

SELECT caller, receiver, duration
FROM phone_calls
WHERE year = 2025
AND month = 7
AND day = 28;

SELECT *
FROM atm_transactions
WHERE year = 2025
AND month = 7
AND day = 28
AND atm_id = (SELECT id FROM atms WHERE location LIKE '%Leggett%');

SELECT *
FROM flights
WHERE origin_airport_id = (
    SELECT id FROM airports WHERE city = 'Fiftyville'
)
AND year = 2025
AND month = 7
AND day = 29
ORDER BY hour
LIMIT 1;

SELECT people.name, passengers.passport_number
FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
WHERE passengers.flight_id = 36;

SELECT *
FROM airports
WHERE id = 4;

SELECT people.name
FROM people
WHERE phone_number IN (
    SELECT receiver
    FROM phone_calls
    WHERE caller = '(367) 555-5103'
    AND year = 2025
    AND month = 7
    AND day = 28
    AND duration < 60
);

SELECT people.name
FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
WHERE passengers.flight_id = 36
AND people.name != 'Bruce';