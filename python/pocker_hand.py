from numpy.f2py.crackfortran import privatepattern
from collections import Counter

class pocker_hand:
    RESULT = ["Loss", "Tie", "Win"]
    VALUES = {
        '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7,
        '8': 8, '9': 9, 'T': 10,
        'J': 11, 'Q': 12, 'K': 13, 'A': 14
    }

    def __init__(self, hand):
        self.hand = hand
        pass

    def compare_with(self, other):
        combo_value_ours = self.get_combo_value(self.hand)
        combo_value_theirs = self.get_combo_value(other.hand)
        if combo_value_ours > combo_value_theirs:
            return self.RESULT[2]
        if combo_value_ours < combo_value_theirs:
            return self.RESULT[0]
        # Same rank
        if self.break_tie(self.hand, other.hand):
            return self.RESULT[2]
        if self.break_tie(other.hand, self.hand):
            return self.RESULT[0]
        return self.RESULT[1]

    def break_tie(self, hand1, hand2):
        vals1 = self.get_values(hand1)
        vals2 = self.get_values(hand2)
        cnt1 = Counter(vals1)
        cnt2 = Counter(vals2)

        groups1 = sorted(cnt1.items(), key=lambda x: (x[1], x[0]), reverse=True)
        groups2 = sorted(cnt2.items(), key=lambda x: (x[1], x[0]), reverse=True)

        for (v1, c1), (v2, c2) in zip(groups1, groups2):
            if v1 != v2:
                return v1 > v2

        sorted1 = sorted(vals1, reverse=True)
        sorted2 = sorted(vals2, reverse=True)
        for v1, v2 in zip(sorted1, sorted2):
            if v1 != v2:
                return v1 > v2
        return False

    def get_combo_value(self, hand):
        if (self.is_royal_flush(hand)):
            return 9
        if (self.is_straight_flush(hand)):
            return 8
        if (self.is_four_of_a_kind(hand)):
            return 7
        if (self.is_full_house(hand)):
            return 6
        if (self.is_flush(hand)):
            return 5
        if (self.is_straight(hand)):
            return 4
        if (self.is_three_of_a_kind(hand)):
            return 3
        if (self.is_two_pairs(hand)):
            return 2
        if (self.is_pair(hand)):
            return 1
        return 0

    def is_high_card(self, ours, theirs):
        our_vals = sorted(self.get_values(ours), reverse=True)
        their_vals = sorted(self.get_values(theirs), reverse=True)

        for o, t in zip(our_vals, their_vals):
            if o != t:
                return o > t
        return False

    def is_pair(self, hand):
        values = self.get_values(hand)
        values_set = set(values)
        if len(values_set) == 5:
            return False
        return True

    def is_two_pairs(self, hand):
        if not self.is_pair(hand):
            return False
        values = self.get_values(hand)
        values_set = set(values)
        if len(values_set) != 3:
            return False
        values_counts = Counter(values)
        sorted_counts = sorted(values_counts.values(), reverse=True)
        if sorted_counts == [2, 2, 1]:
            return True
        return False

    def is_three_of_a_kind(self, hand):
        values = self.get_values(hand)
        values_set = set(values)
        if len(values_set) != 3:
            return False
        values_counts = Counter(values)
        sorted_counts = sorted(values_counts.values(), reverse=True)
        if sorted_counts == [3, 1, 1]:
            return True
        return False

    def is_straight(self, hand):
        values = self.get_values(hand)
        values_set = set(values)
        if len(values_set) != 5:
            return False

        sorted_values = sorted(values)
        if sorted_values[-1] - sorted_values[0] == 4:
            return True

        ace_low_set = {14, 2, 3, 4, 5}
        if values_set == ace_low_set:
            return True

        return False

    def is_flush(self, hand):
        suits = self.get_suits(hand)
        suit_set = set(suits)
        if len(suit_set) != 1:
            return False
        return True

    def is_full_house(self, hand):
        values = self.get_values(hand)
        values_set = set(values)
        if len(values_set) != 2:
            return False
        count_first = list(values).count(next(iter(values_set)))
        if count_first != 3 and count_first != 2:
            return False
        return True

    def is_four_of_a_kind(self, hand):
        values = self.get_values(hand)
        values_set = set(values)
        if len(values_set) != 2:
            return False
        count_first = list(values).count(next(iter(values_set)))
        if count_first != 4 and count_first != 1:
            return False
        return True

    def is_straight_flush(self, hand):
        if not self.is_flush(hand):
            return False
        if not self.is_straight(hand):
            return False
        return True

    def is_royal_flush(self, hand):
        if not self.is_straight_flush(hand):
            return False
        values = self.get_values(hand)
        if not values[0] == 10:
            return False
        return True

    def get_suits(self, hand):
        cards = str(hand).split(" ")
        return [x[1] for x in cards]

    def get_values(self, hand):
        cards = str(hand).split(" ")
        return [self.VALUES[x[0]] for x in cards]
        

def assert_equals(actual, expected, error):
    if actual != expected:
        raise RuntimeError(error)

def run_test(msg, expected, hand, other):
    player, opponent = pocker_hand(hand), pocker_hand(other)
    actual = player.compare_with(opponent)
    print(actual)
    assert_equals(actual, expected, f'{msg}: Failed for hand "{hand}" against opponent hand "{other}"')

def sample_tests():
    run_test("Highest straight flush wins", "Loss", "2H 3H 4H 5H 6H", "KS AS TS QS JS")
    run_test("Straight flush wins of 4 of a kind", "Win", "2H 3H 4H 5H 6H", "AS AD AC AH JD")
    run_test("Highest 4 of a kind wins", "Win", "AS AH 2H AD AC", "JS JD JC JH 3D")
    run_test("4 Of a kind wins of full house", "Loss", "2S AH 2H AS AC", "JS JD JC JH AD")
    run_test("Full house wins of flush", "Win", "2S AH 2H AS AC", "2H 3H 5H 6H 7H")
    run_test("Highest flush wins", "Win", "AS 3S 4S 8S 2S", "2H 3H 5H 6H 7H")
    run_test("Flush wins of straight", "Win", "2H 3H 5H 6H 7H", "2S 3H 4H 5S 6C")
    run_test("Equal straight is tie", "Tie", "2S 3H 4H 5S 6C", "3D 4C 5H 6H 2S")
    run_test("Straight wins of three of a kind", "Win", "2S 3H 4H 5S AD", "AH AC 5H 6H AS")
    run_test("3 Of a kind wins of two pair", "Loss", "2S 2H 4H 5S 4C", "AH AC 5H 6H AS")
    run_test("2 Pair wins of pair", "Win", "2S 2H 4H 5S 4C", "AH AC 5H 6H 7S")
    run_test("Highest pair wins", "Loss", "6S AD 7H 4S AS", "AH AC 5H 6H 7S")
    run_test("Pair wins of nothing", "Loss", "2S AH 4H 5S KC", "AH AC 5H 6H 7S")
    run_test("Highest card loses", "Loss", "2S 3H 6H 7S 9C", "7H 3C TH 6H 9S")
    run_test("Highest card wins", "Win", "4S 5H 6H TS AC", "3S 5H 6H TS AC")
    run_test("Equal cards is tie", "Tie", "2S AH 4H 5S 6C", "AD 4C 5H 6H 2C")


if __name__ == '__main__':
    sample_tests()