
import org.restlet.resource.Get;
import org.restlet.resource.ServerResource;

public class ProductResource extends ServerResource{
	private static volatile Product product = new Product("123", "Hello");
	@Get
	public Product retrieve() {
		return product;
	}
}
