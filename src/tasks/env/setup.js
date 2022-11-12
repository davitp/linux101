import { Typography } from "antd";
import Helmet from "react-helmet";

const { Title, Text } = Typography;

const EnvironmentSetupTask = ({code, embed, titleLevel = 5}) => {

    return <>
        {!embed && <Helmet>
            <title>Setup GNU/Linux Environment ({code})</title>
        </Helmet>}
        <Typography>
            <Title level={titleLevel}>
                Setup GNU/Linux Environment ({code})
            </Title>
            <ul>
                <li>Install any GNU/Linux distribution on a Virtual or Physical Machine.</li>
                <li>Run <Text strong>lsb_release -a {'>>'} $USER.txt</Text> command (if available) in a shell and get the result.</li>
                <li>Run <Text strong>cat /etc/os-release {'>>'} $USER.txt</Text> command (if available) in a shell and get the result.</li>
                <li>Submit $USER.txt file to the Github as a solution for the task.</li>
            </ul>
        </Typography>

    </>
}

export default EnvironmentSetupTask;