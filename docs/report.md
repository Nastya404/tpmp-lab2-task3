# Test Report — Task 3 (TRAIN structure, variant 22)

## Author
Yarmolik Anastasia, group 11

## Test data
Three trains used for normal test:
- Train 101: Grodno, 300 km, 12 kupejnyj wagons, 36 passengers each
- Train 205: Moskva, 2000 km, 15 platskart wagons, 54 passengers each
- Train 310: Grodno, 500 km, 8 kupejnyj wagons, 36 passengers each

---

## Test 1: Normal input (3 trains)

| Check | Expected | Actual | Passed |
|---|---|---|---|
| Trains over 24h | Train 205 (2000/60 = 33.3h) | Train 205 displayed | Yes |
| Train 101 not over 24h | Not displayed (300/60 = 5h) | Not displayed | Yes |
| Train 310 not over 24h | Not displayed (500/60 = 8.3h) | Not displayed | Yes |
| Compartment passengers | 101: 12x36=432, 310: 8x36=288, total=720 | Total: 720 | Yes |
| Trains to Grodno | Train 101 and 310 | Both displayed | Yes |
| Train 205 not to Grodno | Not displayed | Not displayed | Yes |
| Max wagons | Train 205 (15 wagons) | Train 205 displayed | Yes |

---

## Test 2: Negative train count (-1)

| Input | Expected | Actual | Passed |
|---|---|---|---|
| count = -1 | Error message, program exits | "Error: expected positive integer" | Yes |
| No data processed | No output from filters | No output | Yes |

---

## Test 3: Zero train count (0)

| Input | Expected | Actual | Passed |
|---|---|---|---|
| count = 0 | Error message, program exits | "Error: expected positive integer" | Yes |
| No data processed | No output from filters | No output | Yes |

---

## Test 4: Invalid departure time (25:70)

| Input | Expected | Actual | Passed |
|---|---|---|---|
| hours = 25, minutes = 70 | Error: time out of range | "Error: time must be 00:00..23:59" | Yes |
| Program exits | No further output | No further output | Yes |

---

## Test 5: Invalid wagon type ("luxury")

| Input | Expected | Actual | Passed |
|---|---|---|---|
| wagonType = "luxury" | Error: unknown type | "Error: type must be kupejnyj, platskart or obshchij" | Yes |
| Program exits | No further output | No further output | Yes |

---

## Test 6: Negative distance (-500)

| Input | Expected | Actual | Passed |
|---|---|---|---|
| distance = -500 | Error: must be positive | "Error: distance must be positive" | Yes |
| Program exits | No further output | No further output | Yes |

---

## Conclusion

All 6 tests passed. The program correctly:
- processes valid input and produces expected output
- validates all input fields
- reports clear error messages for invalid data
- exits gracefully on errors without processing garbage data
