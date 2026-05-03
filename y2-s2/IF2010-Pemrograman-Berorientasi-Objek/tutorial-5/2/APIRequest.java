public class APIRequest<T> {
    private String endpoint;
    private T payload;

    public APIRequest(String endpoint, T payload) {
        this.endpoint = endpoint;
        this.payload = payload;
    }

    public <U> APIResponse<U> execute(int statusCode, String message,
                                      U responseData) {
        System.out.println("Executing Request to " + endpoint +
                           " with payload: " + payload);
        return new APIResponse<>(statusCode, message, responseData);
    }
}
