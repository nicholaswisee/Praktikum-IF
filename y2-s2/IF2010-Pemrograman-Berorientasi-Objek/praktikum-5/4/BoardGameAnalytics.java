import java.util.*;
import java.util.stream.Collectors;

public class BoardGameAnalytics {

    private List<BoardGame> games;
    private Set<String> players;
    private Map<String, Integer> stockByGame;
    private Map<String, List<Integer>> ratings;

    public BoardGameAnalytics() {
        this.games = new ArrayList<>();
        this.players = new HashSet<>();
        this.stockByGame = new HashMap<>();
        this.ratings = new HashMap<>();
    }

    /**
     * Menambahkan game baru beserta stok awal. Jika game dengan nama sama sudah
     * ada, stoknya ditambah.
     *
     * @param game board game yang ditambahkan
     * @param initialStock stok awal yang ditambahkan
     */
    public void addGame(BoardGame game, int initialStock) {
        boolean exists =
            games.stream().anyMatch(g -> g.getName().equals(game.getName()));

        if (!exists) {
            games.add(game);
        }

        stockByGame.merge(game.getName(), initialStock, Integer::sum);
    }

    /**
     * Menambahkan rating dari seorang pemain untuk sebuah game. Pemain disimpan
     * sebagai pemain unik.
     *
     * @param gameName nama game
     * @param playerName nama pemain
     * @param rating nilai rating
     */
    public void addRating(String gameName, String playerName, int rating) {
        players.add(playerName);
        ratings.computeIfAbsent(gameName, k -> new ArrayList<>()).add(rating);
    }

    /**
     * Menghitung rata-rata rating sebuah game. Jika belum ada rating, hasilnya
     * 0.0.
     *
     * @param gameName nama game
     * @return rata-rata rating
     */
    private double getAverageRating(String gameName) {
        List<Integer> gameRatings = ratings.get(gameName);
        if (gameRatings == null || gameRatings.isEmpty()) {
            return 0.0;
        }
        return gameRatings.stream()
            .mapToInt(Integer::intValue)
            .average()
            .orElse(0.0);
    }

    /**
     * Mengembalikan daftar nama game yang stoknya kurang dari threshold. Hasil
     * diurutkan berdasarkan stok menaik. Jika stok sama, urutkan berdasarkan
     * nama game secara alfabetis.
     *
     * Method ini diharapkan menggunakan Map dan Stream API.
     *
     * @param threshold batas stok
     * @return daftar nama game dengan stok di bawah threshold
     */
    public List<String> getLowStockGames(int threshold) {
        return stockByGame.entrySet()
            .stream()
            .filter(entry -> entry.getValue() < threshold)
            .sorted(
                Comparator.comparingInt(Map.Entry<String, Integer>::getValue)
                    .thenComparing(Map.Entry::getKey))
            .map(Map.Entry::getKey)
            .collect(Collectors.toList());
    }

    /**
     * Mengembalikan daftar nama game yang: - cocok untuk jumlah pemain tertentu
     * - memiliki rata-rata rating minimal tertentu Hasil diurutkan alfabetis.
     *
     * @param playerCount jumlah pemain
     * @param minRating rating minimum
     * @return daftar nama game yang direkomendasikan
     */
    public List<String> getRecommendedGames(int playerCount, double minRating) {
        return games.stream()
            .filter(game
                    -> game.getMinPlayers() <= playerCount &&
                           game.getMaxPlayers() >= playerCount)
            .filter(game -> getAverageRating(game.getName()) >= minRating)
            .map(BoardGame::getName)
            .sorted()
            .collect(Collectors.toList());
    }
}
