import { Typography } from "antd";
import Container from "components/container";
import Helmet from "react-helmet";

const { Title, Paragraph, Text } = Typography;

const IndexPage = () => {

    return <>
        <Helmet>
            <title>Home</title>
        </Helmet>
        <Container>
            <Typography>
                <Title>Welcome to Linux 101</Title>
                <Paragraph>
                    The is the homepage for <Text strong>Linux 101</Text> course: Introduction to software development for Linux. 
                    Website will host all the materials for the course including samples, homeworks, library, and etc. 
                    Everything related to the course is available in a <a target="_blank" rel="noreferrer" href="https://github.com/davitp/linux101">Github repository</a>. 
                </Paragraph>
                <Paragraph>
                </Paragraph>
                <Title level={2}>Guidelines and Resources</Title>
                <Paragraph>
                    We supply a series of design principles, practical patterns and high quality design resources
                    (<Text code>Sketch</Text> and <Text code>Axure</Text>), to help people create their product
                    prototypes beautifully and efficiently.
                </Paragraph>
            </Typography>
        </Container>
    </>
}

export default IndexPage;