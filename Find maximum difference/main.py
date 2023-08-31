def maximum_difference(self, question: List[int]) -> int:
        minimum = question[0]
        maximum = 0
        for q in question[1:]:
            maximum = max(maximum, q - minimum)
            minimum = min(minimum, q)
        return maximum
