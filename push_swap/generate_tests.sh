#!/bin/bash
# ===============================
# Push_swap Stress & Valgrind Test
# ===============================

# Function to generate N random numbers in full 32-bit signed integer range
generate_numbers() {
    local n=$1
    awk -v n="$n" 'BEGIN {
        srand();
        for(i=0;i<n;i++) {
            printf("%d ", int(-2147483648 + rand() * 4294967295));
        }
    }'
}

# Function to run a test case
run_test() {
    local description="$1"
    local numbers="$2"
    echo "=== $description ==="
    
    # Run checker for correctness
    ./push_swap $numbers | ./checker_linux $numbers
    
    # Run Valgrind and capture output
    # Suppress push_swap stdout, keep Valgrind report in stderr
    VALGRIND_OUT=$(valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap $numbers 2>&1 >/dev/null)
    
    # Debug: Show what Valgrind actually outputs (uncomment next line for debugging)
    # echo "DEBUG - Valgrind output:" && echo "$VALGRIND_OUT" && echo "--- END DEBUG ---"
    
    # Check for leaks - look for the LEAK SUMMARY section
    if echo "$VALGRIND_OUT" | grep -A5 "LEAK SUMMARY:" | grep -q "definitely lost: 0 bytes in 0 blocks" && \
       echo "$VALGRIND_OUT" | grep -A5 "LEAK SUMMARY:" | grep -q "indirectly lost: 0 bytes in 0 blocks" && \
       echo "$VALGRIND_OUT" | grep -A5 "LEAK SUMMARY:" | grep -q "possibly lost: 0 bytes in 0 blocks" && \
       echo "$VALGRIND_OUT" | grep -A5 "LEAK SUMMARY:" | grep -q "still reachable: 0 bytes in 0 blocks"; then
        echo "Valgrind OK"
    elif echo "$VALGRIND_OUT" | grep -q "All heap blocks were freed -- no leaks are possible"; then
        echo "Valgrind OK"
    else
        echo "Valgrind KO"
        # Show leak info for debugging
        echo "$VALGRIND_OUT" | grep -A10 "LEAK SUMMARY:" | head -15
    fi
    echo
}

# ===============================
# TEST CASES
# ===============================

# 1. Empty input
run_test "Empty input" ""

# 2. Single element
run_test "Single element" "42"

# 3. Two elements
run_test "Two elements sorted" "1 2"
run_test "Two elements reverse" "2 1"

# 4. Small random sets
run_test "Small random set 1" "5 3 9 1 2"
run_test "Small random set 2" "10 7 4 8 2 6"

# 5. Already sorted / Reverse sorted
run_test "Already sorted" "1 2 3 4 5 6 7 8 9 10"
run_test "Reverse sorted" "10 9 8 7 6 5 4 3 2 1"

# 6. Almost sorted
run_test "Almost sorted" "1 2 3 5 4 6 7 8 10 9"

# 7. Alternating high/low
run_test "Alternating high/low" "10 1 9 2 8 3 7 4 6 5"

# 8. Duplicates
run_test "Duplicates" "1 2 2 3 3 4 5 5"

# 9. Negative numbers
run_test "Negative numbers" "-3 -1 -4 -2 0 2 1 3"

# 10. Medium stress (100 numbers)
NUMS_100=$(generate_numbers 100)
run_test "Medium stress (100 numbers)" "$NUMS_100"

# 11. Large stress (500 numbers)
NUMS_500=$(generate_numbers 500)
run_test "Large stress (500 numbers)" "$NUMS_500"

# 12. Extreme stress (INT_MIN → INT_MAX)
NUMS_500_EXTREME=$(generate_numbers 500)
run_test "Extreme stress (INT_MIN→INT_MAX)" "$NUMS_500_EXTREME"

echo "All tests completed."
