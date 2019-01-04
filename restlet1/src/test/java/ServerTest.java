import java.io.IOException;

import org.junit.After;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

import org.restlet.representation.Representation;
import org.restlet.resource.ClientResource;


public class ServerTest {
	Server server = new Server();
	@Before
	public void setUp() throws Exception {
		server.start(8182);
	}

	@After
	public void tearDown() throws Exception {
		server.stop();
	}

	@Test
	public void test() throws IOException {
		Representation representation = new ClientResource("http://localhost:8182/product").get();
		Assert.assertEquals("application/json", representation.getMediaType().toString());
		Assert.assertEquals("{\"sku\":\"123\", \"title\": \"Hello\"}", representation.getText());
	}

}
