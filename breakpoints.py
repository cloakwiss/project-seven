
def find_lines(filename, serches):
    line_numbers = []

    with open(filename, "r", encoding="utf-8") as f:
        for i, line in enumerate(f, start=1):  # 1-indexed
            for search in serches:
                if search in line:
                    line_numbers.append(i)

    return line_numbers


nums = find_lines("hookdll/hooks.hpp", ["SEND_BEFORE_CALL", "SEND_AFTER_CALL"])

for n in nums:
    print('breakpoint: source_location: "hookdll/hooks.hpp:' + str(n) + ':1"')
