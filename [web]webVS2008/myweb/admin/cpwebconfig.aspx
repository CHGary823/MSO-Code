<%@ Register TagPrefix="uc1" TagName="cpmenu" Src="../control/cpmenu.ascx" %>
<%@ Register TagPrefix="uc1" TagName="cptop" Src="../control/cptop.ascx" %>
<%@ Page language="c#" ValidateRequest="false" Codebehind="cpwebconfig.aspx.cs" AutoEventWireup="false" Inherits="web.admin.cpwebconfig" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN" >
<HTML>
	<HEAD>
		<title>admincp</title>
		<meta content="Microsoft Visual Studio .NET 7.1" name="GENERATOR">
		<meta content="C#" name="CODE_LANGUAGE">
		<meta content="JavaScript" name="vs_defaultClientScript">
		<meta content="http://schemas.microsoft.com/intellisense/ie5" name="vs_targetSchema">
		<SCRIPT language="JavaScript" src="Common/JavaScript/Menu.js"></SCRIPT>
		<LINK href="Common/CSS/Default.CSS" type="text/css" rel="stylesheet">
		<LINK href="Common/CSS/menuStyleXP.CSS" type="text/css" rel="stylesheet">
	</HEAD>
	<body MS_POSITIONING="GridLayout">
		<form id="Form1" method="post" runat="server">
			<uc1:cptop id="Cptop1" runat="server"></uc1:cptop>
			<table id="Table1" cellSpacing="1" cellPadding="3" width="780" border="0">
				<tr>
					<td vAlign="top" width="207" rowSpan="2">
						<table cellSpacing="0" cellPadding="0" width="100%" align="center" border="0">
							<tr bgColor="#bcbcbc">
								<td>
									<table cellSpacing="1" cellPadding="10" width="100%" border="0">
										<tr bgColor="#efefef">
											<td vAlign="top" height="498"><uc1:cpmenu id="Cpmenu1" runat="server"></uc1:cpmenu></td>
										</tr>
										<tr bgColor="#f9f9f9">
											<td height="80">
												<div align="center">
													<p><font color="#ff6633"><A href="../logout.aspx" target="_blank"><b><font color="#ff6666">�]�N�˳�</font></b></A></font></p>
												</div>
											</td>
										</tr>
									</table>
								</td>
							</tr>
						</table>
					</td>
					<td vAlign="top" width="556">
						<table id="Table2" cellSpacing="0" cellPadding="0" width="563" align="center" border="0">
							<tr bgColor="#bcbcbc">
								<td>
									<table id="Table3" cellSpacing="1" cellPadding="8" width="100%" border="0">
										<tr bgColor="#efefef">
											<td vAlign="top" align="left" height="350">
												<TABLE id="Table4" cellSpacing="1" cellPadding="1" width="464" border="0" style="WIDTH: 464px; HEIGHT: 332px">
													<TBODY>
														<TR>
															<TD style="WIDTH: 90px; HEIGHT: 23px">
																<b>�Wվ��Ϣ����</b>
															<TD><FONT face="�����w"></FONT></TD>
														<TR>
															<TD style="WIDTH: 90px; HEIGHT: 23px">�Wվ�Ƿ��P�]</TD>
															<TD style="HEIGHT: 23px">
																<asp:radiobutton id="rbopen" runat="server" Text="�_��" GroupName="webstate"></asp:radiobutton>
																<asp:radiobutton id="rbclose" runat="server" Text="�P�]" GroupName="webstate"></asp:radiobutton></TD>
														</TR>
														<TR>
															<TD style="WIDTH: 90px; HEIGHT: 23px">�Wվ���Q</TD>
															<TD style="HEIGHT: 23px">
																<asp:TextBox id="tbtitle" runat="server" Width="344px"></asp:TextBox></TD>
														</TR>
														<TR>
															<TD style="WIDTH: 90px; HEIGHT: 20px">�WվMeta �P�I�~</TD>
															<TD style="HEIGHT: 20px">
																<asp:TextBox id="tbkeywords" runat="server" Width="264px"></asp:TextBox></FONT></TD>
														</TR>
														<TR>
															<TD style="WIDTH: 90px; HEIGHT: 20px">�WվMeta ����</TD>
															<TD style="HEIGHT: 20px">
																<asp:TextBox id="tbdescription" runat="server" Width="264px"></asp:TextBox></FONT></TD>
														</TR>
														<TR>
															<TD style="WIDTH: 90px">���L�yӋ朽�</FONT></TD>
															<TD style="HEIGHT: 22px">
																<asp:TextBox id="tbcount" runat="server" Width="353px"></asp:TextBox></TD>
														</TR>
														<TR>
															<TD style="WIDTH: 90px">ICP �䰸��Ϣ</TD>
															<TD style="HEIGHT: 22px">
																<asp:TextBox id="tbicpinfo" runat="server" Width="184px"></asp:TextBox></FONT></TD>
														</TR>
														<TR>
															<TD style="WIDTH: 90px; HEIGHT: 66px">�Wվ�P�]��ʾ</TD>
															<TD style="WIDTH: 107px; HEIGHT: 66px">
																<asp:TextBox id="tbclosetext" runat="server" TextMode="MultiLine" Rows="10" Width="268px"></asp:TextBox></TD>
														</TR>
														<TR>
															<TD style="WIDTH: 90px"></TD>
															<TD style="WIDTH: 107px">
																<asp:Button id="btnedit" runat="server" Text="�� �� �� ��"></asp:Button></TD>
														</TR>
													</TBODY>
												</TABLE>
												</FONT>
											</td>
										</tr>
									</table>
								</td>
							</tr>
						</table>
					</td>
				</tr>
			</table>
		</form>
	</body>
</HTML>
