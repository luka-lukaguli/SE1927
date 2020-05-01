using System;
using System.Collections.Specialized;

// https://www.tutorialsteacher.com/csharp/csharp-data-types   --- C#-ის ტიპები

namespace CSharpTypes
{
    internal class Program
    {
        private static void Main()
        {
            Console.Write("Enter Number: ");
            int number1 = int.Parse(Console.ReadLine());

            Console.Write("Enter Number: ");
            int number2 = int.Parse(Console.ReadLine());

            Console.WriteLine($"{number1} + {number2} = {number1 + number2}");

            // დავალება: გააკეთეთ კალკულატორი

            Console.ReadLine();
        }
    }
}