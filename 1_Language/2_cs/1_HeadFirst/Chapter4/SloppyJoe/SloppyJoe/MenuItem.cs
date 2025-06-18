using System;

namespace SloppyJoe
{
    internal class MenuItem
    {
        // 동일한 값이 나오는 것은 샘플 코드에 의도된 동작이다.
        // 이 코드를 통해 책에서 설명하고자 한 것은 .NET의 Random 클래스는 의사난수 생성기라는 점이다.
        // 즉, 동일한 seed 값으로 시작하면 항상 같은 난수 시퀀스를 생성한다.
        public Random Randomizer = new Random(126345);

        public string[] Proteins = { "Roast Beef", "Salami", "Turkey", "Ham", "Pastrami", "Tofu" };
        public string[] Condiments = { "yellow mustard", "brown mustard", "honey mustard", "mayo", "relish", "french dressing" };
        public string[] Breads = { "rye", "white", "wheat", "pumpernickel", "a roll" };

        public string Description = "";
        public string Price;

        public void Generate()
        {
            string randomProtein = Proteins[Randomizer.Next(Proteins.Length)];
            string randomCondiment = Condiments[Randomizer.Next(Condiments.Length)];
            string randomBread = Breads[Randomizer.Next(Breads.Length)];

            Description = randomProtein + " with " + randomCondiment + " on " + randomBread;

            decimal bucks = Randomizer.Next(2, 5);
            decimal cents = Randomizer.Next(1, 98);
            decimal price = bucks + (cents * .01m);

            var usCultureInfo = new System.Globalization.CultureInfo("en-Us");
            Price = price.ToString("c", usCultureInfo);
        }
    }
}
