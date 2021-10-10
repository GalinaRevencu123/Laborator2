
public class Main {
    public static void main(String[] args) {
        System.out.println("Basic Level:");
        System.out.println("Enter your text here:");
        Scanner input = new Scanner(System.in);
        String text = input.nextLine();
        Text textInput = new Text(text);
        System.out.println("Number of sentences: " + textInput.countSentences());
        System.out.println("Number of words:" + textInput.countWords());

        System.out.println("\nAdvanced Level (1):");
        System.out.println("Letters: " + textInput.countLetters());
        System.out.println("Vowels: " + textInput.countVowels());
        System.out.println("Consonants: " + textInput.countConsonants());

        System.out.println("\nAdvanced Level (2):");
        System.out.println("The most frequent word is: " + textInput.getFrequent());
        System.out.println("Longest word is: " + textInput.getLongest());
    }
}