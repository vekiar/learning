import collections
import random

Card = collections.namedtuple('Card', ['rank', 'suit'])

class FrenchDeck:
  ranks = [str(n) for n in range(2, 11)] + list('JQKA')
  suits = 'spades diamonds clubs hearts'.split()

  def __init__(self):
    self._cards = [Card(rank, suit) for suit in self.suits for rank in self.ranks]

  def __len__(self):
    return len(self._cards)

  def __getitem__(self, position):
    return self._cards[position]

# Use namedtuple to construct a simple class to represent individual cards.
# Bundles of attributes with no custom methods.
beer_card = Card('7', 'diamonds')
print(beer_card)

# Point of the example is the class.
deck = FrenchDeck()
print(len(deck))

# We can use <random.choice> to pick a random card.
print(deck[0], deck[-1])
print(random.choice(deck), random.choice(deck), random.choice(deck))

# Deck automatically supports slicing, because <__getitem__> delegates to <[]>
print(deck[:3])
print(deck[12::13])

# And the deck is also iterable:
for card in deck:
  print(card)

for card in reversed(deck):
  print(card)

# If a collection has no <__contains__> method, the <in> operator does a sequential scan
print(Card('Q', 'hearts') in deck)
print(Card('7', 'beasts') in deck)

# How about sorting?
suit_values = dict(spades=3, hearts=2, diamonds=1, clubs=0)

def spades_high(card):
  rank_value = FrenchDeck.ranks.index(card.rank)
  return rank_value * len(suit_values) + suit_values[card.suit]

for card in sorted(deck, key=spades_high):
  print(card)

# How about shuffling?
# As implemented, the class is immutable: the cards and their positions cannot be changed.
