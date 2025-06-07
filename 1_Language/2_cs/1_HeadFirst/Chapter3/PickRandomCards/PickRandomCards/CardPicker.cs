namespace PickRandomCards
{
    internal class CardPicker
    {
        static Random Random = new();

        public static string[] PickSomeCards(int numberOfCards)
        {
            string[] pickedCards = new string[numberOfCards];
            for (int i = 0; i < numberOfCards; i++)
            {
                pickedCards[i] = RandomValue() + " of " + RandomSuit();
            }
            return pickedCards;
        }

        private static string RandomSuit()
        {
            int value = Random.Next(1, 5);

            switch (value)
            {
                case 1:
                    return "Spades";
                case 2:
                    return "Hearts";
                case 3:
                    return "Clubs";
            }
            return "Diamonds";
        }

        private static string RandomValue()
        {
            int value = Random.Next(1, 14);

            switch (value)
            {
                case 1:
                    return "Ace";
                case 11:
                    return "Jack";
                case 12:
                    return "Queen";
                case 13:
                    return "King";
            }
            return value.ToString();
        }
    }
}
