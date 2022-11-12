import Container from "components/container";
import Helmet from "react-helmet";
import { Navigate, useParams } from "react-router-dom";
import { buildTask } from "tasks";

const HomeworkTaskPage = () => {

    const { code } = useParams();
    

    console.log(code);

    return <>
        <Helmet>
            <title>Task Explorer</title>
        </Helmet>
        <Container>
           {buildTask(code, { embed: false, titleLevel: 2 }) || <Navigate to={'/not-found'} replace />}
        </Container>
    </>
}

export default HomeworkTaskPage;