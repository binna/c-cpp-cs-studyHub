using System.Diagnostics;

namespace SwordDamage_WPF_Part1
{
    internal class SwordDamage
    {
        public const int BASE_DAMAGE = 3;
        public const int FLAME_DAMAGE = 2;

        private int Roll;

        private decimal MagicMultiplier = 1m;

        private int FlamingDamage = 0;
        private int Damage;

        public void SetRoll(int newRoll)
        {
            Roll = newRoll;
        }

        public string GetDisplayDamageText()
        {
            return "Rolled " + Roll + " for " + Damage + " HP";
        }

        public void SetMagic(bool isMagic)
        {
            if (isMagic)
            {
                MagicMultiplier = 1.75M;
            }
            else
            {
                MagicMultiplier = 1M;
            }

            CalculateDamage();

            Debug.WriteLine($"2. CalculateDamage finished : {Damage} (roll : {Roll})");
        }

        public void SetFlaming(bool isFlaming)
        {
            CalculateDamage();

            if (isFlaming)
            {
                Damage += FLAME_DAMAGE;
            }

            Debug.WriteLine($"3. CalculateDamage finished : {Damage} (roll : {Roll})");
        }

        private void CalculateDamage()
        {
            Damage = (int)(Roll * MagicMultiplier) + BASE_DAMAGE + FlamingDamage;
            Debug.WriteLine($"1. CalculateDamage finished : {Damage} (roll : {Roll})");
        }
    }
}
