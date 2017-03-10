using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace game_hangman
{
    /** 
     *  Brian Gosalvez
     *  
     *  Classic "hang-man" game
     *      featuring all the boring rules of yore.
     *  
     *  desc: guess the secret word, 
     *          one letter at a time.
     *          betcha can't do it.
     *        
     *  This is the non-encapsulated version;
     *          there could be one extra class 
     *          but the simplicity of the logic 
     *          doesn't need it.
     */
    class Program
    {
        static void Main(string[] args)
        {
            byte part_count = 0;
            bool guessed = false;
            char letter_choice;
            char[] array_secret_word = new char[1];
            char[] array_user_word = new char[1];
            List<char> array_wrong = new List<char>();

            // randomize secret word and make blank array with underscores
            ResetGame(out array_secret_word, out array_user_word);

            // lucky number seven
            while(part_count < 7 && guessed == false)
            {
                // display hangman
                drawHangman(part_count);
                // display blanks/correct letters
                drawLetters(array_user_word);
                // display incorrect guessed letters
                drawWrongGuesses(array_wrong);

                // show tries left
                Console.WriteLine("tries remaining: " + (7 - part_count)+"\n");

                //prompt user, store input for comparison
                Console.WriteLine("enter a letter, \'0\' to quit");
                letter_choice = Console.ReadKey().KeyChar;

                if(letter_choice == '0') // i'd rather check facebook right now.
                {
                    break;
                }
                else    // bring it on, b#$%^
                {
                    // correct guess
                    if (array_secret_word.Contains(letter_choice))
                    {
                        // loop through every letter in the secret word
                        for (int i = 0; i < array_secret_word.Length; i++)
                        {
                            if (array_secret_word[i] == letter_choice)
                            {
                                // fill in correct letters so user can see them
                                array_user_word[i] = letter_choice;
                                // positive Pavlovian praise
                                Console.WriteLine("\ngood :-)");
                            }

                        }

                        // guessed the whole word (!!)
                        if (array_user_word.SequenceEqual(array_secret_word)) // who could've guessed it? java's simpler.
                        {
                            // since these are at beginning of loop, won't be redrawn.
                            // call here to show "final results" 
                            // including fully-spelled word
                            drawHangman(part_count);
                            drawLetters(array_user_word);
                            drawWrongGuesses(array_wrong);

                            guessed = true;
                            // disappointing 'you win' message. 
                            // i can feel the unfulfillment every time
                            // a user wins this game, 
                            // and it makes me giggle a bit.
                            Console.WriteLine("\ncongrats! play again? y/n");

                            if (Console.ReadKey().KeyChar == 'y')  // come at me, bro
                            {
                                // reset all values; choose new word
                                ResetGame(out array_secret_word, out array_user_word);
                                array_wrong = new List<char>();
                                part_count = 0;

                                // stay in loop
                                guessed = false; 
                            }
                            else
                                continue; // exit loop, disp "exit msg"
                        }
                    }
                    else
                    {
                        // add limb
                        part_count++;
                        // scorn
                        Console.WriteLine("\ntry again!");
                        // add letter to "Incorrect guess" bank
                        array_wrong.Add(letter_choice);

                        // fully-drawn hangman
                        if (part_count == 7)
                        {
                            Console.WriteLine("game over! play again? y/n");
                            if (Console.ReadKey().KeyChar == 'y') // what's this "outside" i keep hearing about?
                            {
                                // reset all vals
                                ResetGame(out array_secret_word, out array_user_word);
                                array_wrong = new List<char>();
                                part_count = 0;
                            }
                            else
                                continue; // play basketball instead?
                        }
                    }
                }

                Console.WriteLine(); // clarity
            }

            // exit msg
            Console.WriteLine("\nthanks for playing :-)");

            // hang until user exit. remove to allow a quick subliminal message to flash by.
            Console.Read();
        }

        static void ResetGame(out char[] arrSecret, out char[] arrUser)
        {
            string sSecretWord;

            sSecretWord = ResetSecretWord(); // randomizing function

            // turn that string into a char[]. because C# can't do it himself.
            // this array is for comparison.
            arrSecret = new char[sSecretWord.Length];
            arrSecret = sSecretWord.ToCharArray();

            // we now know the size. let's make this array the size of the aforementioned
            // one and fill it with underscores.
            // this is the array with correct guesses that the user will see.
            arrUser = new char[sSecretWord.Length];
            for(int i=0;i<arrUser.Length;i++)
            {
                arrUser[i] = '_';
            }
        }

        static string ResetSecretWord()
        {
            // you know what this does
            Random rand = new Random();
            return nouns.words[rand.Next(nouns.size - 1)];
        }

        static void drawHangman(byte pc)
        {
            // some tedious shit right here.
            // not so bad with copy & paste, 
            // and thank Glob for the insert key.
            switch(pc)
            {
                case 0:
                    Console.WriteLine(" -----");
                    Console.WriteLine(" |   |");
                    Console.WriteLine("     |");
                    Console.WriteLine("     |"); 
                    Console.WriteLine("     |");
                    Console.WriteLine("     |");
                    Console.WriteLine("   __|__");
                    break;
                case 1:
                    Console.WriteLine(" -----");
                    Console.WriteLine(" |   |");
                    Console.WriteLine(" 0   |");
                    Console.WriteLine("     |"); 
                    Console.WriteLine("     |");
                    Console.WriteLine("     |");
                    Console.WriteLine("   __|__");
                    break;
                case 2:
                    Console.WriteLine(" -----");
                    Console.WriteLine(" |   |");
                    Console.WriteLine(" 0   |");
                    Console.WriteLine(" |   |"); 
                    Console.WriteLine("     |");
                    Console.WriteLine("     |");
                    Console.WriteLine("   __|__");
                    break;
                case 3:
                    Console.WriteLine(" -----");
                    Console.WriteLine(" |   |");
                    Console.WriteLine(" 0   |");
                    Console.WriteLine("\\|   |"); // should line up; backslash needs to be escaped
                    Console.WriteLine("     |");
                    Console.WriteLine("     |");
                    Console.WriteLine("   __|__");
                    break;
                case 4:
                    Console.WriteLine(" -----");
                    Console.WriteLine(" |   |");
                    Console.WriteLine(" 0   |");
                    Console.WriteLine("\\|/  |"); // should line up; backslash needs to be escaped
                    Console.WriteLine("     |");
                    Console.WriteLine("     |");
                    Console.WriteLine("   __|__");
                    break;
                case 5:
                    Console.WriteLine(" -----");
                    Console.WriteLine(" |   |");
                    Console.WriteLine(" 0   |");
                    Console.WriteLine("\\|/  |"); // should line up; backslash needs to be escaped
                    Console.WriteLine(" |   |");
                    Console.WriteLine("     |");
                    Console.WriteLine("   __|__");
                    break;
                case 6:
                    Console.WriteLine(" -----");
                    Console.WriteLine(" |   |");
                    Console.WriteLine(" 0   |");
                    Console.WriteLine("\\|/  |"); // should line up; backslash needs to be escaped
                    Console.WriteLine(" |   |");
                    Console.WriteLine("/    |");
                    Console.WriteLine("   __|__");
                    break;
                case 7:
                    Console.WriteLine(" -----");
                    Console.WriteLine(" |   |");
                    Console.WriteLine(" 0   |");
                    Console.WriteLine("\\|/  |"); // should line up; backslash needs to be escaped
                    Console.WriteLine(" |   |");
                    Console.WriteLine("/ \\  |");
                    Console.WriteLine("   __|__");
                    break;
                default:
                    break;
            }

            /* template
            Console.WriteLine(" -----");
            Console.WriteLine(" |   |");
            Console.WriteLine(" 0   |");
            Console.WriteLine("\\|/  |"); 
            Console.WriteLine(" |   |");
            Console.WriteLine("/ \\  |");
            Console.WriteLine("   __|__");
            */

            Console.WriteLine("\n\n"); // easier to read
        }

        static void drawLetters(char[] ca)
        {
            // draw each correct guess
            // as well as un-guessed letters.
            // space them out for aesthetics.
            foreach(char c in ca)
                Console.Write("{0,2}", c);
            Console.WriteLine("\n\n\n"); // easier to read
        }

        static void drawWrongGuesses(List<char> c)
        {
            // make a wrong-guess bank
            // so user can see what already guessed wrong.
            // guessing these letters still counts as a try,
            // in order to encourage intelligence.
            // we don't need any more hiltons or kardashians.
            Console.WriteLine("\nIncorrect Letters:\n");
            foreach (char letter in c)
                Console.Write("{0,2}", letter);
            Console.WriteLine("\n\n"); // easier to read
        }
    }
}
