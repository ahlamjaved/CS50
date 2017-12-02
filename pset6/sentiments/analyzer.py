import nltk

class Analyzer():
    """Implements sentiment analysis."""

    def __init__(self, positives, negatives):
        """Initialize Analyzer."""

        self.positives = set()
        self.negative = set()

        file = open(positives, 'r')
        for line in file:
            if line.startswith(';'):
                continue
            else:
                self.positives.add(line.rstrip("\n"))

        file = open(negatives, 'r')
        for line in file:
            if line.startswith(';'):
                continue
            else:
                self.negative.add(line.rstrip("\n"))

    def analyze(self, text):
        """Analyze text for sentiment, returning its score."""

        tokenizer = nltk.tokenize.TweetTokenizer()
        tokens = tokenizer.tokenize(text)
        score = 0
        # to iterate over words in tweet (tokens) and see if word is pos or neg
        for str in tokens:
            # check to see if this token is positive or negative
            if str.lower() in self.positives:
                score += 1
            elif str.lower() in self.negative:
                score -= 1
            else:
                continue
        return score
