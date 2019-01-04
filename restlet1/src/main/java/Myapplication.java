import org.restlet.Application;
import org.restlet.Restlet;
import org.restlet.routing.Router;

public class Myapplication extends Application{

	/* (non-Javadoc)
	 * @see org.restlet.Application#getInboundRoot()
	 */
	@Override
	public Restlet getInboundRoot() {
		Router router = new Router();
		router.attach("/product", ProductResource.class);
		return router; 
	}
	
}
