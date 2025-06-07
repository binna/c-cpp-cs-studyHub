namespace PickRandomCards;

class Program
{
    static void Main(string[] args)
    {

        Console.Write("Enter the number of cards to pick: ");
        
        string? line = Console.ReadLine();


        if (int.TryParse(line, out int number))
        {
            foreach (var card in CardPicker.PickSomeCards(number))
            {
                Console.WriteLine(card);
            }
        }
        else
        {
            Console.WriteLine("유효하지 않은 카드를 뽑았습니다.");
        }
    }
}
