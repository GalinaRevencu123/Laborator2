
public class Text {

    String text;
    char[] textArray;
    int sentence = 0;
    int vowel = 0;
    int letter = 0;

    public Text(String text) {
        this.text = text;
        this.textArray = this.text.toCharArray();
    }

    public int countSentences() {
        for (int i = 0; i < this.textArray.length; i++) {

            if (text.charAt(i) == '.' || text.charAt(i) == '?' || text.charAt(i) == '!') {
                sentence++;
            }

        }
        return sentence;
    }

    public int countWords() {
        int count = 1;
        for (int i = 0; i <= text.length() - 1; i++) {
            if (text.charAt(i) == ' ' && text.charAt(i + 1) != ' ') {
                count++;
            }
        }
        return count;
    }
    public int countLetters() {
        for (int i = 0; i < text.length(); i++) {
            if (Character.isLetter(text.charAt(i)))
                letter++;
        }
        return letter;
    }


    public int countVowels() {
        for (int i = 0; i < this.textArray.length; i++) {
            if (text.charAt(i) == 'A' || text.charAt(i) == 'a' || text.charAt(i) == 'E' || text.charAt(i) == 'e'
                    || text.charAt(i) == 'I' || text.charAt(i) == 'i' || text.charAt(i) == 'O'
                    || text.charAt(i) == 'o' || text.charAt(i) == 'U' || text.charAt(i) == 'u'){
                vowel++;
            }
        }
        return vowel;
    }

    public int countConsonants() {
        return (countLetters() - countVowels()) / 2;
    }

    public String getLongest() {
        String[] words = this.text.split("\\s+");
        for (int i = 0; i < words.length; i++) {
            words[i] = words[i].replaceAll("[^\\w]", "");
        }
        int index = 0;
        int elementLength = words[0].length();
        for (int i = 1; i < words.length; i++) {
            if (words[i].length() > elementLength) {
                index = i;
                elementLength = words[i].length();
            }
        }
        return words[index];
    }

    String getFrequent() {

        String[] arr = this.text.split("\\s+");
        HashMap<String, Integer> hs = new HashMap<String, Integer>();

        for (int i = 0; i < arr.length; i++) {

            if (hs.containsKey(arr[i])) {
                hs.put(arr[i], hs.get(arr[i]) + 1);
            } else {
                hs.put(arr[i], 1);
            }
        }

        Set<Map.Entry<String, Integer>> set = hs.entrySet();
        String key = "";
        int value = 0;

        for (Map.Entry<String, Integer> me : set) {
            if (me.getValue() > value) {
                value = me.getValue();
                key = me.getKey();
            }
        }
        return key;
    }
}